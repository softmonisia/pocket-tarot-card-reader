// tarot_data.h
// Auto-generated Tarot card database for ESP32 Tarot device
// All strings stored in flash (PROGMEM) - near-zero RAM cost at rest.
//
// IMPORTANT: 'path' values for Major Arcana (id 0-21) are VERIFIED against the
// actual uploaded asset package (tarot_major_arcana_esp32.zip).
// 'path' values for Minor Arcana (id 22-77) are ASSUMED - they follow the same
// naming convention (local rank 00-13 per suit + lowercase-underscore name),
// but have NOT been verified against real files yet, since those images don't
// exist yet. Re-run the generator script once real Minor Arcana files exist to
// confirm/fix any mismatches (e.g. if slugs differ - punctuation, etc).
#pragma once
#include <Arduino.h>

#define NUM_CARDS 78
#define CARDS_ROOT "/cards/"   // path prefix, e.g. "/cards/" + card.path

enum CardCategory : uint8_t {
  CAT_MAJOR = 0,
  CAT_WANDS,
  CAT_CUPS,
  CAT_SWORDS,
  CAT_PENTACLES
};

// One entry per card. Kept small on purpose.
struct TarotCard {
  const char* name;             // card name (points into flash)
  CardCategory category;
  const char* path;              // relative path under /cards/, e.g. "major/00_the_fool.bmp"
  const char* keywordsUpright;   // comma-separated, e.g. "Hope, Faith, Renewal"
  const char* keywordsReversed;  // comma-separated
};

// ---------------------------------------------------------------
// Flash-resident strings. Each one lives in PROGMEM (flash), not RAM.
// ---------------------------------------------------------------
const char C000_NAME[] PROGMEM = "The Fool";
const char C000_PATH[] PROGMEM = "major/00_the_fool.bmp";
const char C000_UP[]   PROGMEM = "New beginnings, Innocence, Spontaneity, Free spirit, Adventure";
const char C000_REV[]  PROGMEM = "Recklessness, Naivety, Risk-taking, Poor judgment, Distraction";
const char C001_NAME[] PROGMEM = "The Magician";
const char C001_PATH[] PROGMEM = "major/01_the_magician.bmp";
const char C001_UP[]   PROGMEM = "Manifestation, Resourcefulness, Power, Inspired action, Skill";
const char C001_REV[]  PROGMEM = "Manipulation, Poor planning, Untapped talent, Trickery";
const char C002_NAME[] PROGMEM = "The High Priestess";
const char C002_PATH[] PROGMEM = "major/02_the_high_priestess.bmp";
const char C002_UP[]   PROGMEM = "Intuition, Mystery, Subconscious, Inner voice, Secrets";
const char C002_REV[]  PROGMEM = "Hidden agendas, Disconnection, Repressed feelings, Confusion";
const char C003_NAME[] PROGMEM = "The Empress";
const char C003_PATH[] PROGMEM = "major/03_the_empress.bmp";
const char C003_UP[]   PROGMEM = "Abundance, Nurturing, Fertility, Creativity, Nature";
const char C003_REV[]  PROGMEM = "Neglect, Creative block, Dependence, Smothering";
const char C004_NAME[] PROGMEM = "The Emperor";
const char C004_PATH[] PROGMEM = "major/04_the_emperor.bmp";
const char C004_UP[]   PROGMEM = "Authority, Structure, Control, Stability, Leadership";
const char C004_REV[]  PROGMEM = "Domination, Rigidity, Excessive control, Lack of discipline";
const char C005_NAME[] PROGMEM = "The Hierophant";
const char C005_PATH[] PROGMEM = "major/05_the_hierophant.bmp";
const char C005_UP[]   PROGMEM = "Tradition, Conformity, Institutions, Belief systems, Guidance";
const char C005_REV[]  PROGMEM = "Rebellion, Unconventionality, Restriction, Challenging norms";
const char C006_NAME[] PROGMEM = "The Lovers";
const char C006_PATH[] PROGMEM = "major/06_the_lovers.bmp";
const char C006_UP[]   PROGMEM = "Love, Harmony, Partnership, Choices, Alignment";
const char C006_REV[]  PROGMEM = "Disharmony, Imbalance, Misaligned values, Indecision";
const char C007_NAME[] PROGMEM = "The Chariot";
const char C007_PATH[] PROGMEM = "major/07_the_chariot.bmp";
const char C007_UP[]   PROGMEM = "Willpower, Determination, Victory, Control, Ambition";
const char C007_REV[]  PROGMEM = "Lack of direction, Aggression, Obstacles, Self-doubt";
const char C008_NAME[] PROGMEM = "Strength";
const char C008_PATH[] PROGMEM = "major/08_strength.bmp";
const char C008_UP[]   PROGMEM = "Courage, Compassion, Inner strength, Patience, Influence";
const char C008_REV[]  PROGMEM = "Self-doubt, Weakness, Insecurity, Impatience";
const char C009_NAME[] PROGMEM = "The Hermit";
const char C009_PATH[] PROGMEM = "major/09_the_hermit.bmp";
const char C009_UP[]   PROGMEM = "Introspection, Solitude, Guidance, Soul-searching, Wisdom";
const char C009_REV[]  PROGMEM = "Isolation, Loneliness, Withdrawal, Avoidance";
const char C010_NAME[] PROGMEM = "Wheel of Fortune";
const char C010_PATH[] PROGMEM = "major/10_wheel_of_fortune.bmp";
const char C010_UP[]   PROGMEM = "Change, Cycles, Fate, Turning point, Luck";
const char C010_REV[]  PROGMEM = "Bad luck, Resistance to change, Disruption, Setbacks";
const char C011_NAME[] PROGMEM = "Justice";
const char C011_PATH[] PROGMEM = "major/11_justice.bmp";
const char C011_UP[]   PROGMEM = "Fairness, Truth, Law, Cause and effect, Balance";
const char C011_REV[]  PROGMEM = "Unfairness, Dishonesty, Lack of accountability, Bias";
const char C012_NAME[] PROGMEM = "The Hanged Man";
const char C012_PATH[] PROGMEM = "major/12_the_hanged_man.bmp";
const char C012_UP[]   PROGMEM = "Surrender, Letting go, New perspective, Pause, Sacrifice";
const char C012_REV[]  PROGMEM = "Stalling, Resistance, Indecision, Delays";
const char C013_NAME[] PROGMEM = "Death";
const char C013_PATH[] PROGMEM = "major/13_death.bmp";
const char C013_UP[]   PROGMEM = "Endings, Transformation, Transition, Change, Release";
const char C013_REV[]  PROGMEM = "Fear of change, Stagnation, Resistance, Incomplete transition";
const char C014_NAME[] PROGMEM = "Temperance";
const char C014_PATH[] PROGMEM = "major/14_temperance.bmp";
const char C014_UP[]   PROGMEM = "Balance, Moderation, Patience, Purpose, Harmony";
const char C014_REV[]  PROGMEM = "Imbalance, Excess, Discord, Lack of harmony";
const char C015_NAME[] PROGMEM = "The Devil";
const char C015_PATH[] PROGMEM = "major/15_the_devil.bmp";
const char C015_UP[]   PROGMEM = "Bondage, Addiction, Materialism, Restriction, Temptation";
const char C015_REV[]  PROGMEM = "Freedom, Release, Breaking free, Reclaiming power";
const char C016_NAME[] PROGMEM = "The Tower";
const char C016_PATH[] PROGMEM = "major/16_the_tower.bmp";
const char C016_UP[]   PROGMEM = "Sudden change, Upheaval, Chaos, Revelation, Disaster";
const char C016_REV[]  PROGMEM = "Avoiding disaster, Delayed change, Fear of change, Resistance";
const char C017_NAME[] PROGMEM = "The Star";
const char C017_PATH[] PROGMEM = "major/17_the_star.bmp";
const char C017_UP[]   PROGMEM = "Hope, Faith, Renewal, Inspiration, Serenity";
const char C017_REV[]  PROGMEM = "Despair, Disconnection, Lack of faith, Discouragement";
const char C018_NAME[] PROGMEM = "The Moon";
const char C018_PATH[] PROGMEM = "major/18_the_moon.bmp";
const char C018_UP[]   PROGMEM = "Illusion, Fear, Anxiety, Subconscious, Confusion";
const char C018_REV[]  PROGMEM = "Releasing fear, Clarity, Repressed emotions, Deception uncovered";
const char C019_NAME[] PROGMEM = "The Sun";
const char C019_PATH[] PROGMEM = "major/19_the_sun.bmp";
const char C019_UP[]   PROGMEM = "Joy, Success, Vitality, Positivity, Confidence";
const char C019_REV[]  PROGMEM = "Temporary sadness, Lack of clarity, Overconfidence, Delays";
const char C020_NAME[] PROGMEM = "Judgement";
const char C020_PATH[] PROGMEM = "major/20_judgement.bmp";
const char C020_UP[]   PROGMEM = "Rebirth, Inner calling, Reflection, Awakening, Absolution";
const char C020_REV[]  PROGMEM = "Self-doubt, Harsh judgment, Ignoring the call, Guilt";
const char C021_NAME[] PROGMEM = "The World";
const char C021_PATH[] PROGMEM = "major/21_the_world.bmp";
const char C021_UP[]   PROGMEM = "Completion, Fulfillment, Wholeness, Accomplishment, Travel";
const char C021_REV[]  PROGMEM = "Incompletion, Lack of closure, Shortcuts, Delays";
const char C022_NAME[] PROGMEM = "Ace of Wands";
const char C022_PATH[] PROGMEM = "wands/00_ace_of_wands.bmp";
const char C022_UP[]   PROGMEM = "Inspiration, New venture, Creative spark, Growth, Potential";
const char C022_REV[]  PROGMEM = "Delays, Lack of motivation, False start, Blocked creativity";
const char C023_NAME[] PROGMEM = "Two of Wands";
const char C023_PATH[] PROGMEM = "wands/01_two_of_wands.bmp";
const char C023_UP[]   PROGMEM = "Planning, Progress, Decisions, Discovery, Ambition";
const char C023_REV[]  PROGMEM = "Fear of unknown, Lack of planning, Playing it safe";
const char C024_NAME[] PROGMEM = "Three of Wands";
const char C024_PATH[] PROGMEM = "wands/02_three_of_wands.bmp";
const char C024_UP[]   PROGMEM = "Expansion, Foresight, Progress, Opportunity, Leadership";
const char C024_REV[]  PROGMEM = "Delays, Lack of foresight, Setbacks, Frustration";
const char C025_NAME[] PROGMEM = "Four of Wands";
const char C025_PATH[] PROGMEM = "wands/03_four_of_wands.bmp";
const char C025_UP[]   PROGMEM = "Celebration, Harmony, Homecoming, Community, Stability";
const char C025_REV[]  PROGMEM = "Instability, Lack of harmony, Conflict, Delayed celebration";
const char C026_NAME[] PROGMEM = "Five of Wands";
const char C026_PATH[] PROGMEM = "wands/04_five_of_wands.bmp";
const char C026_UP[]   PROGMEM = "Conflict, Competition, Tension, Disagreement, Rivalry";
const char C026_REV[]  PROGMEM = "Avoiding conflict, Resolution, Inner conflict, Diffused tension";
const char C027_NAME[] PROGMEM = "Six of Wands";
const char C027_PATH[] PROGMEM = "wands/05_six_of_wands.bmp";
const char C027_UP[]   PROGMEM = "Victory, Recognition, Success, Confidence, Pride";
const char C027_REV[]  PROGMEM = "Setback, Lack of recognition, Self-doubt, Fall from grace";
const char C028_NAME[] PROGMEM = "Seven of Wands";
const char C028_PATH[] PROGMEM = "wands/06_seven_of_wands.bmp";
const char C028_UP[]   PROGMEM = "Perseverance, Defensiveness, Standing ground, Challenge, Resilience";
const char C028_REV[]  PROGMEM = "Overwhelm, Giving up, Exhaustion, Yielding";
const char C029_NAME[] PROGMEM = "Eight of Wands";
const char C029_PATH[] PROGMEM = "wands/07_eight_of_wands.bmp";
const char C029_UP[]   PROGMEM = "Swift action, Momentum, Progress, Quick decisions, Movement";
const char C029_REV[]  PROGMEM = "Delays, Frustration, Miscommunication, Slowing down";
const char C030_NAME[] PROGMEM = "Nine of Wands";
const char C030_PATH[] PROGMEM = "wands/08_nine_of_wands.bmp";
const char C030_UP[]   PROGMEM = "Resilience, Persistence, Caution, Boundaries, Courage";
const char C030_REV[]  PROGMEM = "Exhaustion, Paranoia, Defensiveness, Giving up";
const char C031_NAME[] PROGMEM = "Ten of Wands";
const char C031_PATH[] PROGMEM = "wands/09_ten_of_wands.bmp";
const char C031_UP[]   PROGMEM = "Burden, Responsibility, Hard work, Stress, Achievement";
const char C031_REV[]  PROGMEM = "Overwhelm, Burnout, Delegation, Release of burden";
const char C032_NAME[] PROGMEM = "Page of Wands";
const char C032_PATH[] PROGMEM = "wands/10_page_of_wands.bmp";
const char C032_UP[]   PROGMEM = "Enthusiasm, Exploration, Free spirit, Curiosity, New ideas";
const char C032_REV[]  PROGMEM = "Lack of direction, Procrastination, Impulsiveness, Restlessness";
const char C033_NAME[] PROGMEM = "Knight of Wands";
const char C033_PATH[] PROGMEM = "wands/11_knight_of_wands.bmp";
const char C033_UP[]   PROGMEM = "Energy, Passion, Adventure, Impulsiveness, Action";
const char C033_REV[]  PROGMEM = "Recklessness, Impatience, Delays, Frustration";
const char C034_NAME[] PROGMEM = "Queen of Wands";
const char C034_PATH[] PROGMEM = "wands/12_queen_of_wands.bmp";
const char C034_UP[]   PROGMEM = "Confidence, Independence, Determination, Warmth, Vibrancy";
const char C034_REV[]  PROGMEM = "Insecurity, Jealousy, Demanding, Temperamental";
const char C035_NAME[] PROGMEM = "King of Wands";
const char C035_PATH[] PROGMEM = "wands/13_king_of_wands.bmp";
const char C035_UP[]   PROGMEM = "Leadership, Vision, Boldness, Entrepreneurship, Charisma";
const char C035_REV[]  PROGMEM = "Impulsiveness, Arrogance, Ruthlessness, Poor judgment";
const char C036_NAME[] PROGMEM = "Ace of Cups";
const char C036_PATH[] PROGMEM = "cups/00_ace_of_cups.bmp";
const char C036_UP[]   PROGMEM = "New love, Emotional beginning, Compassion, Intuition, Joy";
const char C036_REV[]  PROGMEM = "Emotional block, Repressed feelings, Emptiness, Missed connection";
const char C037_NAME[] PROGMEM = "Two of Cups";
const char C037_PATH[] PROGMEM = "cups/01_two_of_cups.bmp";
const char C037_UP[]   PROGMEM = "Partnership, Connection, Mutual attraction, Unity, Harmony";
const char C037_REV[]  PROGMEM = "Imbalance, Disconnect, Broken communication, Tension";
const char C038_NAME[] PROGMEM = "Three of Cups";
const char C038_PATH[] PROGMEM = "cups/02_three_of_cups.bmp";
const char C038_UP[]   PROGMEM = "Friendship, Celebration, Community, Joy, Collaboration";
const char C038_REV[]  PROGMEM = "Overindulgence, Gossip, Isolation, Conflict";
const char C039_NAME[] PROGMEM = "Four of Cups";
const char C039_PATH[] PROGMEM = "cups/03_four_of_cups.bmp";
const char C039_UP[]   PROGMEM = "Apathy, Contemplation, Discontent, Boredom, Reevaluation";
const char C039_REV[]  PROGMEM = "Awareness, Renewed interest, Acceptance, New motivation";
const char C040_NAME[] PROGMEM = "Five of Cups";
const char C040_PATH[] PROGMEM = "cups/04_five_of_cups.bmp";
const char C040_UP[]   PROGMEM = "Loss, Grief, Regret, Disappointment, Focus on past";
const char C040_REV[]  PROGMEM = "Acceptance, Moving on, Forgiveness, Healing";
const char C041_NAME[] PROGMEM = "Six of Cups";
const char C041_PATH[] PROGMEM = "cups/05_six_of_cups.bmp";
const char C041_UP[]   PROGMEM = "Nostalgia, Memories, Innocence, Reunion, Childhood";
const char C041_REV[]  PROGMEM = "Stuck in past, Naivety, Unrealistic expectations, Moving forward";
const char C042_NAME[] PROGMEM = "Seven of Cups";
const char C042_PATH[] PROGMEM = "cups/06_seven_of_cups.bmp";
const char C042_UP[]   PROGMEM = "Choices, Fantasy, Illusion, Wishful thinking, Options";
const char C042_REV[]  PROGMEM = "Clarity, Focused decisions, Reality check, Overcoming illusion";
const char C043_NAME[] PROGMEM = "Eight of Cups";
const char C043_PATH[] PROGMEM = "cups/07_eight_of_cups.bmp";
const char C043_UP[]   PROGMEM = "Walking away, Seeking truth, Disillusionment, Transition, Introspection";
const char C043_REV[]  PROGMEM = "Fear of moving on, Stagnation, Avoidance, Hesitation";
const char C044_NAME[] PROGMEM = "Nine of Cups";
const char C044_PATH[] PROGMEM = "cups/08_nine_of_cups.bmp";
const char C044_UP[]   PROGMEM = "Satisfaction, Contentment, Gratitude, Wish fulfilled, Comfort";
const char C044_REV[]  PROGMEM = "Overindulgence, Dissatisfaction, Smugness, Unfulfilled wishes";
const char C045_NAME[] PROGMEM = "Ten of Cups";
const char C045_PATH[] PROGMEM = "cups/09_ten_of_cups.bmp";
const char C045_UP[]   PROGMEM = "Harmony, Fulfillment, Family, Happiness, Emotional security";
const char C045_REV[]  PROGMEM = "Broken family, Disharmony, Misaligned values, Unhappiness";
const char C046_NAME[] PROGMEM = "Page of Cups";
const char C046_PATH[] PROGMEM = "cups/10_page_of_cups.bmp";
const char C046_UP[]   PROGMEM = "Creativity, Intuition, Curiosity, Emotional message, New feelings";
const char C046_REV[]  PROGMEM = "Emotional immaturity, Insecurity, Unrealistic ideas, Disappointment";
const char C047_NAME[] PROGMEM = "Knight of Cups";
const char C047_PATH[] PROGMEM = "cups/11_knight_of_cups.bmp";
const char C047_UP[]   PROGMEM = "Romance, Charm, Idealism, Following heart, Imagination";
const char C047_REV[]  PROGMEM = "Moodiness, Unrealistic expectations, Jealousy, Deception";
const char C048_NAME[] PROGMEM = "Queen of Cups";
const char C048_PATH[] PROGMEM = "cups/12_queen_of_cups.bmp";
const char C048_UP[]   PROGMEM = "Compassion, Empathy, Emotional security, Intuition, Nurturing";
const char C048_REV[]  PROGMEM = "Insecurity, Overwhelm, Codependency, Emotional imbalance";
const char C049_NAME[] PROGMEM = "King of Cups";
const char C049_PATH[] PROGMEM = "cups/13_king_of_cups.bmp";
const char C049_UP[]   PROGMEM = "Emotional balance, Compassion, Diplomacy, Wisdom, Calm";
const char C049_REV[]  PROGMEM = "Moodiness, Manipulation, Emotional volatility, Coldness";
const char C050_NAME[] PROGMEM = "Ace of Swords";
const char C050_PATH[] PROGMEM = "swords/00_ace_of_swords.bmp";
const char C050_UP[]   PROGMEM = "Clarity, Breakthrough, New idea, Truth, Mental power";
const char C050_REV[]  PROGMEM = "Confusion, Miscommunication, Chaos, Clouded judgment";
const char C051_NAME[] PROGMEM = "Two of Swords";
const char C051_PATH[] PROGMEM = "swords/01_two_of_swords.bmp";
const char C051_UP[]   PROGMEM = "Indecision, Stalemate, Difficult choice, Avoidance, Balance";
const char C051_REV[]  PROGMEM = "Confusion, Overwhelm, Forced decision, Information overload";
const char C052_NAME[] PROGMEM = "Three of Swords";
const char C052_PATH[] PROGMEM = "swords/02_three_of_swords.bmp";
const char C052_UP[]   PROGMEM = "Heartbreak, Grief, Sorrow, Betrayal, Emotional pain";
const char C052_REV[]  PROGMEM = "Healing, Forgiveness, Moving on, Releasing pain";
const char C053_NAME[] PROGMEM = "Four of Swords";
const char C053_PATH[] PROGMEM = "swords/03_four_of_swords.bmp";
const char C053_UP[]   PROGMEM = "Rest, Recovery, Contemplation, Peace, Recuperation";
const char C053_REV[]  PROGMEM = "Restlessness, Burnout, Stagnation, Forced activity";
const char C054_NAME[] PROGMEM = "Five of Swords";
const char C054_PATH[] PROGMEM = "swords/04_five_of_swords.bmp";
const char C054_UP[]   PROGMEM = "Conflict, Win at all costs, Betrayal, Tension, Discord";
const char C054_REV[]  PROGMEM = "Reconciliation, Regret, Moving past conflict, Compromise";
const char C055_NAME[] PROGMEM = "Six of Swords";
const char C055_PATH[] PROGMEM = "swords/05_six_of_swords.bmp";
const char C055_UP[]   PROGMEM = "Transition, Moving on, Healing journey, Recovery, Progress";
const char C055_REV[]  PROGMEM = "Resistance to change, Unresolved issues, Stuck, Difficult transition";
const char C056_NAME[] PROGMEM = "Seven of Swords";
const char C056_PATH[] PROGMEM = "swords/06_seven_of_swords.bmp";
const char C056_UP[]   PROGMEM = "Deception, Strategy, Secrecy, Trickery, Self-interest";
const char C056_REV[]  PROGMEM = "Guilt, Getting caught, Coming clean, Self-deceit";
const char C057_NAME[] PROGMEM = "Eight of Swords";
const char C057_PATH[] PROGMEM = "swords/07_eight_of_swords.bmp";
const char C057_UP[]   PROGMEM = "Restriction, Feeling trapped, Self-imposed limits, Helplessness, Anxiety";
const char C057_REV[]  PROGMEM = "Freedom, Self-empowerment, New perspective, Release";
const char C058_NAME[] PROGMEM = "Nine of Swords";
const char C058_PATH[] PROGMEM = "swords/08_nine_of_swords.bmp";
const char C058_UP[]   PROGMEM = "Anxiety, Worry, Fear, Nightmares, Despair";
const char C058_REV[]  PROGMEM = "Relief, Hope, Releasing fear, Recovery";
const char C059_NAME[] PROGMEM = "Ten of Swords";
const char C059_PATH[] PROGMEM = "swords/09_ten_of_swords.bmp";
const char C059_UP[]   PROGMEM = "Ending, Betrayal, Collapse, Painful ending, Rock bottom";
const char C059_REV[]  PROGMEM = "Recovery, Resilience, Inevitable end, Slow healing";
const char C060_NAME[] PROGMEM = "Page of Swords";
const char C060_PATH[] PROGMEM = "swords/10_page_of_swords.bmp";
const char C060_UP[]   PROGMEM = "Curiosity, Vigilance, New ideas, Mental energy, Honesty";
const char C060_REV[]  PROGMEM = "Gossip, Scattered thoughts, Impulsiveness, Deception";
const char C061_NAME[] PROGMEM = "Knight of Swords";
const char C061_PATH[] PROGMEM = "swords/11_knight_of_swords.bmp";
const char C061_UP[]   PROGMEM = "Action, Ambition, Assertiveness, Haste, Determination";
const char C061_REV[]  PROGMEM = "Recklessness, Impulsiveness, Aggression, Burnout";
const char C062_NAME[] PROGMEM = "Queen of Swords";
const char C062_PATH[] PROGMEM = "swords/12_queen_of_swords.bmp";
const char C062_UP[]   PROGMEM = "Independence, Clarity, Direct communication, Perception, Boundaries";
const char C062_REV[]  PROGMEM = "Coldness, Bitterness, Harsh judgment, Isolation";
const char C063_NAME[] PROGMEM = "King of Swords";
const char C063_PATH[] PROGMEM = "swords/13_king_of_swords.bmp";
const char C063_UP[]   PROGMEM = "Authority, Intellect, Truth, Discipline, Clarity";
const char C063_REV[]  PROGMEM = "Manipulation, Abuse of power, Rigidity, Cruelty";
const char C064_NAME[] PROGMEM = "Ace of Pentacles";
const char C064_PATH[] PROGMEM = "pentacles/00_ace_of_pentacles.bmp";
const char C064_UP[]   PROGMEM = "New opportunity, Abundance, Prosperity, Manifestation, Security";
const char C064_REV[]  PROGMEM = "Missed opportunity, Lack of planning, Instability, Greed";
const char C065_NAME[] PROGMEM = "Two of Pentacles";
const char C065_PATH[] PROGMEM = "pentacles/01_two_of_pentacles.bmp";
const char C065_UP[]   PROGMEM = "Balance, Adaptability, Time management, Prioritization, Juggling";
const char C065_REV[]  PROGMEM = "Imbalance, Overwhelm, Disorganization, Overcommitment";
const char C066_NAME[] PROGMEM = "Three of Pentacles";
const char C066_PATH[] PROGMEM = "pentacles/02_three_of_pentacles.bmp";
const char C066_UP[]   PROGMEM = "Teamwork, Collaboration, Skill, Craftsmanship, Learning";
const char C066_REV[]  PROGMEM = "Lack of teamwork, Disorganization, Poor quality, Conflict";
const char C067_NAME[] PROGMEM = "Four of Pentacles";
const char C067_PATH[] PROGMEM = "pentacles/03_four_of_pentacles.bmp";
const char C067_UP[]   PROGMEM = "Security, Control, Conservation, Saving, Possessiveness";
const char C067_REV[]  PROGMEM = "Letting go, Overspending, Insecurity, Materialism";
const char C068_NAME[] PROGMEM = "Five of Pentacles";
const char C068_PATH[] PROGMEM = "pentacles/04_five_of_pentacles.bmp";
const char C068_UP[]   PROGMEM = "Hardship, Financial loss, Isolation, Insecurity, Poverty";
const char C068_REV[]  PROGMEM = "Recovery, Improved finances, Support, Renewed hope";
const char C069_NAME[] PROGMEM = "Six of Pentacles";
const char C069_PATH[] PROGMEM = "pentacles/05_six_of_pentacles.bmp";
const char C069_UP[]   PROGMEM = "Generosity, Charity, Giving and receiving, Balance, Support";
const char C069_REV[]  PROGMEM = "Debt, Selfishness, Strings attached, Power imbalance";
const char C070_NAME[] PROGMEM = "Seven of Pentacles";
const char C070_PATH[] PROGMEM = "pentacles/06_seven_of_pentacles.bmp";
const char C070_UP[]   PROGMEM = "Patience, Investment, Long-term view, Assessment, Growth";
const char C070_REV[]  PROGMEM = "Impatience, Lack of reward, Poor investment, Frustration";
const char C071_NAME[] PROGMEM = "Eight of Pentacles";
const char C071_PATH[] PROGMEM = "pentacles/07_eight_of_pentacles.bmp";
const char C071_UP[]   PROGMEM = "Craftsmanship, Diligence, Mastery, Skill-building, Dedication";
const char C071_REV[]  PROGMEM = "Perfectionism, Lack of focus, Mediocrity, Impatience";
const char C072_NAME[] PROGMEM = "Nine of Pentacles";
const char C072_PATH[] PROGMEM = "pentacles/08_nine_of_pentacles.bmp";
const char C072_UP[]   PROGMEM = "Abundance, Independence, Self-sufficiency, Luxury, Reward";
const char C072_REV[]  PROGMEM = "Overwork, Financial setback, Dependence, Superficiality";
const char C073_NAME[] PROGMEM = "Ten of Pentacles";
const char C073_PATH[] PROGMEM = "pentacles/09_ten_of_pentacles.bmp";
const char C073_UP[]   PROGMEM = "Legacy, Wealth, Family, Security, Long-term success";
const char C073_REV[]  PROGMEM = "Financial loss, Family conflict, Instability, Broken tradition";
const char C074_NAME[] PROGMEM = "Page of Pentacles";
const char C074_PATH[] PROGMEM = "pentacles/10_page_of_pentacles.bmp";
const char C074_UP[]   PROGMEM = "Ambition, Diligence, New opportunity, Study, Manifestation";
const char C074_REV[]  PROGMEM = "Procrastination, Lack of progress, Unrealistic goals, Distraction";
const char C075_NAME[] PROGMEM = "Knight of Pentacles";
const char C075_PATH[] PROGMEM = "pentacles/11_knight_of_pentacles.bmp";
const char C075_UP[]   PROGMEM = "Reliability, Diligence, Patience, Hard work, Routine";
const char C075_REV[]  PROGMEM = "Stagnation, Boredom, Stubbornness, Laziness";
const char C076_NAME[] PROGMEM = "Queen of Pentacles";
const char C076_PATH[] PROGMEM = "pentacles/12_queen_of_pentacles.bmp";
const char C076_UP[]   PROGMEM = "Nurturing, Practicality, Abundance, Security, Down-to-earth";
const char C076_REV[]  PROGMEM = "Neglect, Imbalance, Smothering, Financial insecurity";
const char C077_NAME[] PROGMEM = "King of Pentacles";
const char C077_PATH[] PROGMEM = "pentacles/13_king_of_pentacles.bmp";
const char C077_UP[]   PROGMEM = "Wealth, Stability, Leadership, Discipline, Abundance";
const char C077_REV[]  PROGMEM = "Greed, Stubbornness, Financial mismanagement, Materialism";

// ---------------------------------------------------------------
// The deck itself, also stored in flash (PROGMEM).
// To read an entry at runtime, copy it into a local TarotCard variable
// with memcpy_P() first (see usage example in chat / README).
// ---------------------------------------------------------------
const TarotCard tarotDeck[NUM_CARDS] PROGMEM = {
  { C000_NAME, CAT_MAJOR, C000_PATH, C000_UP, C000_REV },
  { C001_NAME, CAT_MAJOR, C001_PATH, C001_UP, C001_REV },
  { C002_NAME, CAT_MAJOR, C002_PATH, C002_UP, C002_REV },
  { C003_NAME, CAT_MAJOR, C003_PATH, C003_UP, C003_REV },
  { C004_NAME, CAT_MAJOR, C004_PATH, C004_UP, C004_REV },
  { C005_NAME, CAT_MAJOR, C005_PATH, C005_UP, C005_REV },
  { C006_NAME, CAT_MAJOR, C006_PATH, C006_UP, C006_REV },
  { C007_NAME, CAT_MAJOR, C007_PATH, C007_UP, C007_REV },
  { C008_NAME, CAT_MAJOR, C008_PATH, C008_UP, C008_REV },
  { C009_NAME, CAT_MAJOR, C009_PATH, C009_UP, C009_REV },
  { C010_NAME, CAT_MAJOR, C010_PATH, C010_UP, C010_REV },
  { C011_NAME, CAT_MAJOR, C011_PATH, C011_UP, C011_REV },
  { C012_NAME, CAT_MAJOR, C012_PATH, C012_UP, C012_REV },
  { C013_NAME, CAT_MAJOR, C013_PATH, C013_UP, C013_REV },
  { C014_NAME, CAT_MAJOR, C014_PATH, C014_UP, C014_REV },
  { C015_NAME, CAT_MAJOR, C015_PATH, C015_UP, C015_REV },
  { C016_NAME, CAT_MAJOR, C016_PATH, C016_UP, C016_REV },
  { C017_NAME, CAT_MAJOR, C017_PATH, C017_UP, C017_REV },
  { C018_NAME, CAT_MAJOR, C018_PATH, C018_UP, C018_REV },
  { C019_NAME, CAT_MAJOR, C019_PATH, C019_UP, C019_REV },
  { C020_NAME, CAT_MAJOR, C020_PATH, C020_UP, C020_REV },
  { C021_NAME, CAT_MAJOR, C021_PATH, C021_UP, C021_REV },
  { C022_NAME, CAT_WANDS, C022_PATH, C022_UP, C022_REV },
  { C023_NAME, CAT_WANDS, C023_PATH, C023_UP, C023_REV },
  { C024_NAME, CAT_WANDS, C024_PATH, C024_UP, C024_REV },
  { C025_NAME, CAT_WANDS, C025_PATH, C025_UP, C025_REV },
  { C026_NAME, CAT_WANDS, C026_PATH, C026_UP, C026_REV },
  { C027_NAME, CAT_WANDS, C027_PATH, C027_UP, C027_REV },
  { C028_NAME, CAT_WANDS, C028_PATH, C028_UP, C028_REV },
  { C029_NAME, CAT_WANDS, C029_PATH, C029_UP, C029_REV },
  { C030_NAME, CAT_WANDS, C030_PATH, C030_UP, C030_REV },
  { C031_NAME, CAT_WANDS, C031_PATH, C031_UP, C031_REV },
  { C032_NAME, CAT_WANDS, C032_PATH, C032_UP, C032_REV },
  { C033_NAME, CAT_WANDS, C033_PATH, C033_UP, C033_REV },
  { C034_NAME, CAT_WANDS, C034_PATH, C034_UP, C034_REV },
  { C035_NAME, CAT_WANDS, C035_PATH, C035_UP, C035_REV },
  { C036_NAME, CAT_CUPS, C036_PATH, C036_UP, C036_REV },
  { C037_NAME, CAT_CUPS, C037_PATH, C037_UP, C037_REV },
  { C038_NAME, CAT_CUPS, C038_PATH, C038_UP, C038_REV },
  { C039_NAME, CAT_CUPS, C039_PATH, C039_UP, C039_REV },
  { C040_NAME, CAT_CUPS, C040_PATH, C040_UP, C040_REV },
  { C041_NAME, CAT_CUPS, C041_PATH, C041_UP, C041_REV },
  { C042_NAME, CAT_CUPS, C042_PATH, C042_UP, C042_REV },
  { C043_NAME, CAT_CUPS, C043_PATH, C043_UP, C043_REV },
  { C044_NAME, CAT_CUPS, C044_PATH, C044_UP, C044_REV },
  { C045_NAME, CAT_CUPS, C045_PATH, C045_UP, C045_REV },
  { C046_NAME, CAT_CUPS, C046_PATH, C046_UP, C046_REV },
  { C047_NAME, CAT_CUPS, C047_PATH, C047_UP, C047_REV },
  { C048_NAME, CAT_CUPS, C048_PATH, C048_UP, C048_REV },
  { C049_NAME, CAT_CUPS, C049_PATH, C049_UP, C049_REV },
  { C050_NAME, CAT_SWORDS, C050_PATH, C050_UP, C050_REV },
  { C051_NAME, CAT_SWORDS, C051_PATH, C051_UP, C051_REV },
  { C052_NAME, CAT_SWORDS, C052_PATH, C052_UP, C052_REV },
  { C053_NAME, CAT_SWORDS, C053_PATH, C053_UP, C053_REV },
  { C054_NAME, CAT_SWORDS, C054_PATH, C054_UP, C054_REV },
  { C055_NAME, CAT_SWORDS, C055_PATH, C055_UP, C055_REV },
  { C056_NAME, CAT_SWORDS, C056_PATH, C056_UP, C056_REV },
  { C057_NAME, CAT_SWORDS, C057_PATH, C057_UP, C057_REV },
  { C058_NAME, CAT_SWORDS, C058_PATH, C058_UP, C058_REV },
  { C059_NAME, CAT_SWORDS, C059_PATH, C059_UP, C059_REV },
  { C060_NAME, CAT_SWORDS, C060_PATH, C060_UP, C060_REV },
  { C061_NAME, CAT_SWORDS, C061_PATH, C061_UP, C061_REV },
  { C062_NAME, CAT_SWORDS, C062_PATH, C062_UP, C062_REV },
  { C063_NAME, CAT_SWORDS, C063_PATH, C063_UP, C063_REV },
  { C064_NAME, CAT_PENTACLES, C064_PATH, C064_UP, C064_REV },
  { C065_NAME, CAT_PENTACLES, C065_PATH, C065_UP, C065_REV },
  { C066_NAME, CAT_PENTACLES, C066_PATH, C066_UP, C066_REV },
  { C067_NAME, CAT_PENTACLES, C067_PATH, C067_UP, C067_REV },
  { C068_NAME, CAT_PENTACLES, C068_PATH, C068_UP, C068_REV },
  { C069_NAME, CAT_PENTACLES, C069_PATH, C069_UP, C069_REV },
  { C070_NAME, CAT_PENTACLES, C070_PATH, C070_UP, C070_REV },
  { C071_NAME, CAT_PENTACLES, C071_PATH, C071_UP, C071_REV },
  { C072_NAME, CAT_PENTACLES, C072_PATH, C072_UP, C072_REV },
  { C073_NAME, CAT_PENTACLES, C073_PATH, C073_UP, C073_REV },
  { C074_NAME, CAT_PENTACLES, C074_PATH, C074_UP, C074_REV },
  { C075_NAME, CAT_PENTACLES, C075_PATH, C075_UP, C075_REV },
  { C076_NAME, CAT_PENTACLES, C076_PATH, C076_UP, C076_REV },
  { C077_NAME, CAT_PENTACLES, C077_PATH, C077_UP, C077_REV },
};
