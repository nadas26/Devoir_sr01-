#ifndef EX1_h
#define EX1_h
#define N 5

// EX 1,2
void entrer(float* points, int pointsTaille);
float pointMaximal(float* points,int pointsTaille);
float pointMinimal(float* points,int pointsTaille);
float pointMoyen(float* points,int pointsTaille);

// EX 3,4,5
void construireNotes(int *notes, float *points);
void graphiqueEnBatons(int* notes);
void graphiqueEnNuage(int* notes);




#endif // EX1_h
