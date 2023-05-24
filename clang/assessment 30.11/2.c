#include <stdio.h>
#include <math.h>
// #include <stdlib.h>
#include <string.h>

struct Record {
  int year;

  enum RecordType {
    PLANET,
    FEAT
  } type;

  union {
    struct { int x, y, z; } planet;
	  char feat[100];
  } rec;
};

// (x ^ 2 + y ^ 2 + z ^ 2) ^ 0.5
int countR(int x, int y, int z)
{
  return (int)ceil(sqrt((x * x + y * y + z * z)));
}

int greatness(struct Record data[], int size)
{
  int am = 0;

  for (int i = 0; i < size; ++i)
  {
    if (data[i].type == PLANET)
    {
      am += countR(data[i].rec.planet.x, data[i].rec.planet.y, data[i].rec.planet.z);
    }

    if (data[i].type == FEAT)
    {
      am += strlen(data[i].rec.feat);
    }
  }

  return am;
}
