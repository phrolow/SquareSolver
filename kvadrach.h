enum Roots { NO_ROOT, ONE_ROOT, TWO_ROOTS, ALL_ROOTS };
enum Mode { NORMAL, DEBUG };

const Mode MODE = NORMAL;
const double EPSILON = 0.0001;
const int MAXLINE = 1000;

double get(char k);
int compare(double a, double b);
enum Roots linecase(double a, double b, double *x1);
enum Roots sqrcase(double a, double b, double c, double *x1, double *x2);
void fixzero(double *a);
void solve(double a, double b, double c, enum Roots *nRoot, double *x1, double *x2);
