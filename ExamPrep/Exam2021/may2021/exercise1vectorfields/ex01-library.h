#ifndef EX01_LIBRARY_H_
#define EX01_LIBRARY_H_

struct Vector {
    double x;
    double y;
};

Vector **createField(unsigned int m, unsigned int n, Vector v);
void displayField(Vector **A, unsigned int m, unsigned int n);
void addFields(Vector **A, Vector **B, Vector **C,
               unsigned int m, unsigned int n);
void scaleField(Vector **A, double c, unsigned int m, unsigned int n);
void deleteField(Vector **A, unsigned int nRows);

#endif /* EX01_LIBRARY_H_ */
