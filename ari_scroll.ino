
//Bienvenido a mi primer Github ! a partir de un taller que hice en Göra MakerSpace en 2017 
// te traigo mi codigo, tiene al principio una luz que luego se convierte en culebrita, luego
//Se convierte en mi logo en scroll con colores de mi logo y todo 
// y al final colores random
//Disfrutalo y alteralo como quieras ! 

#include<FastLED.h>
#define LED_PIN     D3
#define LED_TYPE    WS2812B
#define COLOR_ORDER GRB
#define f false
#define t true

const uint8_t kMatrixWidth  = 4;
const uint8_t kMatrixHeight = 4;
#define NUM_LEDS (kMatrixWidth * kMatrixHeight)

int BRIGHTNESS = 40;   // this is half brightness
CRGB leds[kMatrixWidth * kMatrixHeight];

#define amarillo CRGB::Yellow 
#define black CRGB::Black 
#define rojo CRGB::Red

int loop_cnt = 0;
uint16_t speed = 20;
static uint16_t x;
static uint16_t y;
static uint16_t z;
uint16_t scale = 31;
uint8_t noise[kMatrixWidth][kMatrixHeight];

// Fill the x/y array of 8-bit noise values using the inoise8 function.

void setup() {
  LEDS.addLeds<LED_TYPE,LED_PIN,COLOR_ORDER>(leds,NUM_LEDS);
  FastLED.setBrightness(BRIGHTNESS);
  // Initialize our coordinates to some random values
  x = random16();
  y = random16();
  z = random16();
}

#define frames 35

CRGB matrix[frames][4][4] = {



{
    {black, black, black, black},
    {CRGB::MediumBlue, black, black, black},
    {CRGB::MediumBlue, black, black, black},
    {CRGB::MediumBlue, black, black, black}
  },

{
    {CRGB::MediumBlue, black, black, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, black, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, black, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, black, black}
  },

{
    {CRGB::MediumBlue, CRGB::MediumBlue, black, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue, black},
    {CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue, black}
  },

{
    {black, CRGB::MediumBlue, CRGB::MediumBlue, black},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue}
  },

  
{
    {black, CRGB::MediumBlue, CRGB::MediumBlue, black},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {CRGB::MediumBlue,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue}
  },

  
{
    {black, black, CRGB::MediumBlue, CRGB::MediumBlue},
    {black,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {black,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue},
    {black,CRGB::MediumBlue, CRGB::MediumBlue, CRGB::MediumBlue}
  },

{
    {black, black, black, CRGB::MediumBlue},
    {black,black, CRGB::MediumBlue, CRGB::MediumBlue},
    {black,black, CRGB::MediumBlue, CRGB::MediumBlue},
    {black, black, CRGB::MediumBlue, CRGB::MediumBlue}
  },

{
    {black, black, black, black},
    {CRGB::DeepPink,black, black, CRGB::MediumBlue},
    {black,black, black, CRGB::MediumBlue},
    {CRGB::DeepPink, black, black, CRGB::MediumBlue}
  },

{
    {CRGB::DeepPink, black, black, black},
    {CRGB::DeepPink, CRGB::DeepPink, black, black},
    {CRGB::DeepPink, black, black, black},
    {CRGB::DeepPink, CRGB::DeepPink, black, black}
  },

  {
    {CRGB::DeepPink, CRGB::DeepPink, black, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black},
    {CRGB::DeepPink, CRGB::DeepPink, black, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black}
  },

  {
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink}
  },

  {
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, black},
    {CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink}
  },


  {
    {black, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink},
    {black, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink},
    {black, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink},
    {black, CRGB::DeepPink, CRGB::DeepPink, CRGB::DeepPink}
  },

{
    {black, black, CRGB::DeepPink, CRGB::DeepPink},
    {black, black, CRGB::DeepPink, CRGB::DeepPink},
    {black, black, CRGB::DeepPink, CRGB::DeepPink},
    {black, black, CRGB::DeepPink, CRGB::DeepPink}
  },

{
    {CRGB::Chartreuse, black, black, CRGB::DeepPink},
    {CRGB::Chartreuse, black, black, CRGB::DeepPink},
    {CRGB::Chartreuse, black, black, CRGB::DeepPink},
    {CRGB::Chartreuse, black, black, CRGB::DeepPink}
  },

{
    {CRGB::Chartreuse, CRGB::Chartreuse, black, black},
    {CRGB::Chartreuse, CRGB::Chartreuse, black, black},
    {CRGB::Chartreuse, CRGB::Chartreuse, black, black},
    {CRGB::Chartreuse, CRGB::Chartreuse, black, black}
  },

{
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black}
  },

{
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black},
    {black, CRGB::Chartreuse, CRGB::Chartreuse, black}
  },

{
    {black, black, CRGB::Chartreuse, CRGB::Chartreuse},
    {black, black, CRGB::Chartreuse, CRGB::Chartreuse},
    {black, black, CRGB::Chartreuse, CRGB::Chartreuse},
    {black, black, CRGB::Chartreuse, CRGB::Chartreuse}
  },

{
    {black, black, black, CRGB::Chartreuse},
    {black, black, black, CRGB::Chartreuse},
    {black, black, black, CRGB::Chartreuse},
    {black, black, black, CRGB::Chartreuse}
  },

{
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

  {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },
{
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

   {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },

  {
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },
{
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

  {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },
{
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

   {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },

  {
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },
  {
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

  {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },
{
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },

   {
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black},
    {black, black, black, black}
  },

  {
    {CRGB::Aqua, CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange},
    {CRGB::Tomato, CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink},
    {CRGB::DarkGreen, CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple},
    {CRGB::DarkOrange, CRGB::LightPink, CRGB::Purple, CRGB::WhiteSmoke}
  },
  
};

void loop() {
  /*fillnoise8();*/

  for(int i = 0; i< kMatrixHeight; i++) {
    for(int j = 0; j< kMatrixWidth; j++) {
      leds[i*kMatrixWidth + j] = matrix[loop_cnt%frames][i][j];
    }
  }
  FastLED.show();
  delay(50);
  for(int i = 0; i< kMatrixHeight; i++) {
    for(int j = 0; j<kMatrixWidth; j++) {
      leds[i*kMatrixWidth + j] = CRGB::Black;
    }
  }
  delay(50);
  loop_cnt++;
  
}

