# pocket-tarot-card-reader
🔮 Interactive ESP32-powered Tarot reader featuring a full 78-card deck, random upright/reversed draws, card meanings, custom pixel-art artwork, microSD storage, and touchscreen navigation. Built with C++/Arduino, ESP32, ILI9341 and XPT2046.
#include <Arduino.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_FT6206.h>
#include <pgmspace.h>

#include "tarot_data.h"

// ======================================================
// ESP32 + DISPLAY
// ======================================================

#define TFT_CS   5
#define TFT_DC   2
#define TFT_RST  4

#define TOUCH_SDA 21
#define TOUCH_SCL 22

Adafruit_ILI9341 tft =
  Adafruit_ILI9341(TFT_CS, TFT_DC, TFT_RST);

Adafruit_FT6206 touch =
  Adafruit_FT6206();


// ======================================================
// COLORS
// ======================================================

#define COLOR_BG       0x0842
#define COLOR_GOLD     0xD6B4
#define COLOR_GOLD_DK  0x8C60
#define COLOR_WHITE    0xFFFF
#define COLOR_MUTED    0xAD55


// ======================================================
// APP STATES
// ======================================================

enum AppState {
  STATE_HOME,
  STATE_CARD_VIEW,
  STATE_KEYWORDS
};

AppState state = STATE_HOME;


// ======================================================
// CURRENT DRAW
// ======================================================

uint8_t currentCardId = 0;
bool currentReversed = false;

CardCategory currentCategory;

char cardName[40];
char uprightKeywords[180];
char reversedKeywords[180];


// ======================================================
// TOUCH DEBOUNCE
// ======================================================



// ======================================================
// LOAD CARD FROM FLASH
// ======================================================

void loadCard(uint8_t id) {

  TarotCard card;

  memcpy_P(
    &card,
    &tarotDeck[id],
    sizeof(TarotCard)
  );

  strncpy_P(
    cardName,
    card.name,
    sizeof(cardName) - 1
  );

  cardName[sizeof(cardName) - 1] = '\0';


  strncpy_P(
    uprightKeywords,
    card.keywordsUpright,
    sizeof(uprightKeywords) - 1
  );

  uprightKeywords[
    sizeof(uprightKeywords) - 1
  ] = '\0';


  strncpy_P(
    reversedKeywords,
    card.keywordsReversed,
    sizeof(reversedKeywords) - 1
  );

  reversedKeywords[
    sizeof(reversedKeywords) - 1
  ] = '\0';


  currentCategory =
    card.category;
}


// ======================================================
// CATEGORY NAME
// ======================================================

const char* categoryName(CardCategory category) {

  switch (category) {

    case CAT_MAJOR:
      return "MAJOR ARCANA";

    case CAT_WANDS:
      return "WANDS";

    case CAT_CUPS:
      return "CUPS";

    case CAT_SWORDS:
      return "SWORDS";

    case CAT_PENTACLES:
      return "PENTACLES";
  }

  return "";
}


// ======================================================
// CENTERED TEXT
// ======================================================

void drawCentered(
  const char* text,
  int16_t y,
  uint8_t size,
  uint16_t color
) {

  tft.setTextSize(size);
  tft.setTextColor(color, COLOR_BG);

  int16_t x1;
  int16_t y1;

  uint16_t w;
  uint16_t h;

  tft.getTextBounds(
    text,
    0,
    0,
    &x1,
    &y1,
    &w,
    &h
  );

  int16_t x =
    (tft.width() - w) / 2;

  if (x < 4) {
    x = 4;
  }

  tft.setCursor(x, y);
  tft.print(text);
}


// ======================================================
// BUTTON HELPER
// ======================================================

bool insideButton(
  int16_t px,
  int16_t py,
  int16_t x,
  int16_t y,
  int16_t w,
  int16_t h
) {

  return (
    px >= x &&
    px <= x + w &&
    py >= y &&
    py <= y + h
  );
}


// ======================================================
// HOME SCREEN
// ======================================================

void drawHomeScreen() {

  state = STATE_HOME;

  tft.fillScreen(COLOR_BG);


  // stars

  const int starX[] = {
    18, 45, 205, 220,
    30, 190, 60, 215
  };

  const int starY[] = {
    20, 48, 25, 65,
    100, 110, 170, 155
  };

  for (int i = 0; i < 8; i++) {

    tft.drawPixel(
      starX[i],
      starY[i],
      COLOR_GOLD
    );
  }


  // Crescent moon

  tft.fillCircle(
    120,
    50,
    18,
    COLOR_GOLD
  );

  tft.fillCircle(
    128,
    44,
    18,
    COLOR_BG
  );


  drawCentered(
    "TAROT",
    90,
    4,
    COLOR_GOLD
  );


  drawCentered(
    "A SMALL GUIDE FOR",
    145,
    1,
    COLOR_WHITE
  );


  drawCentered(
    "A BRIGHTER TOMORROW",
    160,
    1,
    COLOR_WHITE
  );


  // DRAW button

  tft.fillRoundRect(
    38,
    218,
    164,
    64,
    8,
    COLOR_GOLD_DK
  );

  tft.fillRoundRect(
    42,
    222,
    156,
    56,
    7,
    COLOR_GOLD
  );

  tft.setTextColor(
    COLOR_BG,
    COLOR_GOLD
  );

  tft.setTextSize(2);

  tft.setCursor(
    58,
    243
  );

  tft.print(
    "DRAW CARD"
  );


  Serial.println();
  Serial.println("===== HOME =====");
  Serial.println("Touch DRAW CARD");
}


// ======================================================
// CARD SCREEN
// ======================================================

void drawCardScreen() {

  state =
    STATE_CARD_VIEW;


  tft.fillScreen(
    COLOR_BG
  );


  // Outer Tarot frame

  tft.drawRoundRect(
    12,
    12,
    216,
    296,
    8,
    COLOR_GOLD
  );

  tft.drawRoundRect(
    16,
    16,
    208,
    288,
    7,
    COLOR_GOLD_DK
  );


  // Card number

  char idText[20];

  snprintf(
    idText,
    sizeof(idText),
    "CARD %d / 78",
    currentCardId + 1
  );

  drawCentered(
    idText,
    32,
    1,
    COLOR_MUTED
  );


  // Category

  drawCentered(
    categoryName(
      currentCategory
    ),
    52,
    1,
    COLOR_GOLD
  );


  // Decorative diamond

  tft.drawLine(
    120,
    80,
    145,
    105,
    COLOR_GOLD
  );

  tft.drawLine(
    145,
    105,
    120,
    130,
    COLOR_GOLD
  );

  tft.drawLine(
    120,
    130,
    95,
    105,
    COLOR_GOLD
  );

  tft.drawLine(
    95,
    105,
    120,
    80,
    COLOR_GOLD
  );


  // Card name

  drawCentered(
    cardName,
    150,
    2,
    COLOR_WHITE
  );


  // Orientation

  drawCentered(
    currentReversed
      ? "REVERSED"
      : "UPRIGHT",
    188,
    2,
    COLOR_GOLD
  );


  // KEYWORDS button

  tft.drawRoundRect(
    18,
    225,
    96,
    42,
    5,
    COLOR_GOLD
  );

  tft.setTextColor(
    COLOR_GOLD,
    COLOR_BG
  );

  tft.setTextSize(1);

  tft.setCursor(
    38,
    242
  );

  tft.print(
    "KEYWORDS"
  );


  // DRAW AGAIN button

  tft.drawRoundRect(
    126,
    225,
    96,
    42,
    5,
    COLOR_GOLD
  );

  tft.setCursor(
    142,
    242
  );

  tft.print(
    "DRAW AGAIN"
  );


  // HOME button

  tft.drawRoundRect(
    82,
    278,
    76,
    24,
    4,
    COLOR_GOLD_DK
  );

  tft.setCursor(
    108,
    286
  );

  tft.print(
    "HOME"
  );


  Serial.println();
  Serial.println("===== CARD =====");

  Serial.print("Card: ");
  Serial.println(cardName);

  Serial.print("Orientation: ");

  Serial.println(
    currentReversed
      ? "REVERSED"
      : "UPRIGHT"
  );
}


// ======================================================
// KEYWORD BULLET
// ======================================================

void drawKeyword(
  const char* keyword,
  int y
) {

  tft.fillCircle(
    29,
    y + 3,
    2,
    COLOR_GOLD
  );

  tft.setTextColor(
    COLOR_WHITE,
    COLOR_BG
  );

  tft.setTextSize(1);

  tft.setCursor(
    39,
    y
  );

  tft.print(
    keyword
  );
}


// ======================================================
// KEYWORDS SCREEN
// ======================================================

void drawKeywordsScreen() {

  state =
    STATE_KEYWORDS;


  tft.fillScreen(
    COLOR_BG
  );


  tft.drawRect(
    8,
    8,
    224,
    304,
    COLOR_GOLD
  );

  tft.drawRect(
    11,
    11,
    218,
    298,
    COLOR_GOLD_DK
  );


  drawCentered(
    cardName,
    28,
    2,
    COLOR_GOLD
  );


  drawCentered(
    currentReversed
      ? "REVERSED"
      : "UPRIGHT",
    62,
    1,
    COLOR_WHITE
  );


  drawCentered(
    "KEYWORDS",
    88,
    1,
    COLOR_MUTED
  );


  char buffer[180];


  if (
    currentReversed
  ) {

    strncpy(
      buffer,
      reversedKeywords,
      sizeof(buffer) - 1
    );

  } else {

    strncpy(
      buffer,
      uprightKeywords,
      sizeof(buffer) - 1
    );
  }


  buffer[
    sizeof(buffer) - 1
  ] = '\0';


  int y = 115;


  char* token =
    strtok(
      buffer,
      ","
    );


  while (
    token != nullptr &&
    y < 235
  ) {

    while (
      *token == ' '
    ) {

      token++;
    }


    drawKeyword(
      token,
      y
    );


    y += 24;


    token =
      strtok(
        nullptr,
        ","
      );
  }


  // BACK

  tft.drawRoundRect(
    55,
    255,
    130,
    40,
    6,
    COLOR_GOLD
  );


  drawCentered(
    "BACK",
    270,
    2,
    COLOR_GOLD
  );


  Serial.println();
  Serial.println(
    "===== KEYWORDS ====="
  );
}


// ======================================================
// RANDOM DRAW
// ======================================================

void drawNewCard() {

  currentCardId =
    random(
      0,
      NUM_CARDS
    );


  currentReversed =
    random(
      0,
      2
    );


  loadCard(
    currentCardId
  );


  drawCardScreen();
}


// ======================================================
// TOUCH HANDLER
// ======================================================

void handleTouch(
  int16_t x,
  int16_t y
) {

  Serial.print(
    "Touch: "
  );

  Serial.print(x);

  Serial.print(",");

  Serial.println(y);


  // ----------------------------------------------------
  // HOME
  // ----------------------------------------------------

  if (
    state ==
    STATE_HOME
  ) {

    if (
      insideButton(
        x,
        y,
        42,
        222,
        156,
        56
      )
    ) {

      drawNewCard();
    }
  }


  // ----------------------------------------------------
  // CARD VIEW
  // ----------------------------------------------------

  else if (
    state ==
    STATE_CARD_VIEW
  ) {

    // KEYWORDS

    if (
      insideButton(
        x,
        y,
        18,
        225,
        96,
        42
      )
    ) {

      drawKeywordsScreen();
    }


    // DRAW AGAIN

    else if (
      insideButton(
        x,
        y,
        126,
        225,
        96,
        42
      )
    ) {

      drawNewCard();
    }


    // HOME

    else if (
      insideButton(
        x,
        y,
        82,
        278,
        76,
        24
      )
    ) {

      drawHomeScreen();
    }
  }


  // ----------------------------------------------------
  // KEYWORDS
  // ----------------------------------------------------

  else if (
    state ==
    STATE_KEYWORDS
  ) {

    if (
      insideButton(
        x,
        y,
        55,
        255,
        130,
        40
      )
    ) {

      // Return to SAME card
      // SAME orientation

      drawCardScreen();
    }
  }
}


// ======================================================
// POLL TOUCH
// ======================================================

void pollTouch() {

  static unsigned long lastAcceptedTouch = 0;

  // Nothing touching the screen
  if (!touch.touched()) {
    return;
  }

  // Prevent one click from triggering repeatedly
  if (millis() - lastAcceptedTouch < 250) {
    return;
  }

  TS_Point p = touch.getPoint();

  // Correct Wokwi coordinates
  int16_t x = 239 - p.x;
  int16_t y = 319 - p.y;

  x = constrain(x, 0, 239);
  y = constrain(y, 0, 319);

  Serial.print("Touch: ");
  Serial.print(x);
  Serial.print(",");
  Serial.println(y);

  lastAcceptedTouch = millis();

  handleTouch(x, y);
}


// ======================================================
// SERIAL FALLBACK
//
// D = draw
// K = keywords
// B = back
// H = home
//
// ======================================================

void pollSerial() {

  if (
    !Serial.available()
  ) {

    return;
  }


  char command =
    Serial.read();


  if (
    command == '\n' ||
    command == '\r'
  ) {

    return;
  }


  if (
    command >= 'a' &&
    command <= 'z'
  ) {

    command -= 32;
  }


  if (
    state ==
    STATE_HOME
  ) {

    if (
      command == 'D'
    ) {

      drawNewCard();
    }
  }


  else if (
    state ==
    STATE_CARD_VIEW
  ) {

    if (
      command == 'K'
    ) {

      drawKeywordsScreen();
    }

    else if (
      command == 'D'
    ) {

      drawNewCard();
    }

    else if (
      command == 'H'
    ) {

      drawHomeScreen();
    }
  }


  else if (
    state ==
    STATE_KEYWORDS
  ) {

    if (
      command == 'B'
    ) {

      drawCardScreen();
    }
  }
}


// ======================================================
// SETUP
// ======================================================

void setup() {

  Serial.begin(
    115200
  );


  // I2C for Wokwi touchscreen

  Wire.begin(
    TOUCH_SDA,
    TOUCH_SCL
  );


  // TFT

  tft.begin();

  tft.setRotation(
    0
  );


  // FT6206 touchscreen

  if (
    !touch.begin(40)
  ) {

    Serial.println(
      "ERROR: Touch controller not found!"
    );

  } else {

    Serial.println(
      "Touch controller: OK"
    );
  }


  randomSeed(
    esp_random()
  );


  drawHomeScreen();
}


// ======================================================
// LOOP
// ======================================================

void loop() {

  pollTouch();
  pollSerial();

  delay(2);
}
