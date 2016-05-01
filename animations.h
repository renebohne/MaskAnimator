// 1,2,3,4,5,6,7,8
// 9,10,11,12,13,14,x,x
// 15,16,17,18,19,20,21,22

/*
 * fill scenes: neurons
 * the video shows the seven emotions: 
 * fear (thunder with sound)
 * surprise (firework)
 * happiness (sunrise)
 * sadness (sunset)
 * anger (abstract firework with explosion sounds)
 * shy (face of a girl)
 * disguist (kaleidoscope with vizuals and in the end it turns out to be a worm)
 * 
 */

const uint8_t FRAME_EMPTY[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0
};

//// SAD /////////////////////////////////////////////////////////////////////////////////////////////////////
// 8,13,22 white (mouth)
// 5,6,7  19,20,21 blue (tears)
// 2,16 white (eyes)

const uint8_t FRAME_SAD0[] PROGMEM = 
{
  0,0,0, 255,255,255, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255
};

const uint8_t FRAME_SAD1[] PROGMEM = 
{
  0,0,0, 255,255,255, 0,0,0, 0,0,0, 0,0,255, 0,0,0, 0,0,0, 255,255,255,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,255, 0,0,0, 0,0,0, 255,255,255
};

const uint8_t FRAME_SAD2[] PROGMEM = 
{
  0,0,0, 255,255,255, 0,0,0, 0,0,0, 0,0,255, 0,0,255, 0,0,0, 255,255,255,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,255, 0,0,255, 0,0,0, 255,255,255
};

const uint8_t FRAME_SAD3[] PROGMEM = 
{
  0,0,0, 255,255,255, 0,0,0, 0,0,0, 0,0,255, 0,0,255, 0,0,255, 255,255,255,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,255,255, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,255, 0,0,255, 0,0,255, 255,255,255
};




//// FEAR /////////////////////////////////////////////////////////////////////////////////////////////////////
//circle 1: 5, 11, 12,19
//circle 2: 2, 4, 6, 10, 13,16, 18, 20
//circle 3: 1,3,7,8,9, 14, 15, 17, 21, 22

const uint8_t FRAME_FEAR0[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 255,0,0, 255,0,0, 0,0,0, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 0,0,0, 0,0,0, 0,0,0
};

const uint8_t FRAME_FEAR1[] PROGMEM = 
{
  0,0,0, 128,128,0, 0,0,0, 128,128,0, 0,0,0, 128,128,0, 0,0,0, 0,0,0,
  0,0,0, 128,128,0, 0,0,0, 0,0,0, 128,128,0, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 128,128,0, 0,0,0, 128,128,0, 0,0,0, 128,128,0, 0,0,0, 0,0,0
};


const uint8_t FRAME_FEAR2[] PROGMEM = 
{
  255,174,66, 0,0,0, 255,174,66, 0,0,0, 0,0,0, 0,0,0, 255,174,66, 255,174,66,
  255,174,66, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,174,66, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  255,174,66, 0,0,0, 255,174,66, 0,0,0, 0,0,0, 0,0,0, 255,174,66, 255,174,66,
};


const uint8_t FRAME_FEAR3[] PROGMEM = 
{
  255,174,66, 128,128,0, 255,174,66, 128,128,0, 255,0,0, 128,128,0, 255,174,66, 255,174,66,
  255,174,66, 128,128,0, 255,0,0, 255,0,0, 128,128,0, 255,174,66, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  255,174,66, 128,128,0, 255,174,66, 128,128,0, 255,0,0, 128,128,0, 255,174,66, 255,174,66,
};



//// DISGUST /////////////////////////////////////////////////////////////////////////////////////////////////////
//red cross: 1, 5,6,7, 11, 15, 19, 20, 21

const uint8_t FRAME_DISGUST0[] PROGMEM = 
{
  255,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 255,0,0, 255,0,0, 0,0,0,
  0,0,0, 0,0,0, 255,0,0, 0,0,0, 0,0,0, 0,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  255,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 255,0,0, 255,0,0, 0,0,0
};


//// HAPPY ///////////////////////////////////////////////////////////////////////////////////////////////////////
const uint8_t FRAME_HAPPY0[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,180,0, 0,180,0, 0,180,0, 0,220,0, 0,225,0, 0,250,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,180,0, 0,200,0, 0,0,0, 0,255,0, 0,255,0, 0,225,0, 255,180,0, 255,180,0
};

const uint8_t FRAME_HAPPY1[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,180,0, 0,180,0, 0,180,0, 255,220,0, 255,180,0, 255,180,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,180,0, 0,200,0, 0,0,0, 0,255,0, 0,255,0, 225,230,0, 255,180,0, 255,180,0
};

const uint8_t FRAME_HAPPY2[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,180,0, 0,180,0, 0,180,0, 255,220,0, 255,180,0, 255,180,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,180,0, 0,200,0, 0,0,0, 0,255,0, 0,255,0, 225,230,0, 255,180,0, 255,180,0
};

const uint8_t FRAME_HAPPY3[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,180,0, 0,180,0, 255,230,0, 255,230,0, 255,180,0, 255,180,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,180,0, 0,200,0, 0,0,0, 255,250,0, 255,240,0, 225,240,0, 255,180,0, 255,180,0
};

const uint8_t FRAME_HAPPY4[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,180,0, 255,230,0, 255,230,0, 255,230,0, 255,180,0, 255,180,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,180,0, 255,230,0, 0,0,0, 255,250,0, 255,240,0, 225,240,0, 255,180,0, 255,180,0
};

const uint8_t FRAME_HAPPY5[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  255,230,0, 255,230,0, 255,230,0, 255,230,0, 255,190,0, 255,190,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  255,230,0, 255,230,0, 0,0,0, 255,250,0, 255,240,0, 225,240,0, 255,190,0, 255,190,0
};




//// ANGER ///////////////////////////////////////////////////////////////////////////////////////////////////////
const uint8_t FRAME_ANGER[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 255,0,0
};
const uint8_t FRAME_ANGER0[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,0,0, 255,0,0, 255,0,0
};

const uint8_t FRAME_ANGER1[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 0,0,0, 255,100,0, 255,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 255,100,0, 255,0,0, 255,0,0, 255,0,0
};

const uint8_t FRAME_ANGER2[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 0,0,0, 255,120,0, 255,100,0, 255,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
   0,0,0, 0,0,0, 255,100,0, 255,0,0, 255,100,0, 255,0,0, 255,0,0, 255,0,0
};

const uint8_t FRAME_ANGER3[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  0,0,0, 255,180,0, 255,120,0, 255,100,0, 255,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
 0,0,0, 255,180,0, 255,100,0, 255,0,0, 255,100,0, 255,0,0, 255,0,0, 255,0,0
};

const uint8_t FRAME_ANGER4[] PROGMEM = 
{
  0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0, 0,0,0,
  255,200,0, 255,180,0, 255,120,0, 255,100,0, 255,0,0, 255,0,0, RESERVED,RESERVED,RESERVED, RESERVED,RESERVED,RESERVED,
  255,200,0, 255,180,0, 255,100,0, 255,0,0, 255,100,0, 255,0,0, 255,0,0, 255,0,0
};

