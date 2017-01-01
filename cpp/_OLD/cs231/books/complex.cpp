class Complex {
	double real;
	double imag;

public:
	Complex();
	Complex(double);
	Complex(double, double);
	Complex(Complex const&);
	~Complex();

	double Real() const;
	double Imag() const;
	double R() const;
	double Theta() const;
	void Put(ostream&) const;

	void SetReal(double);
	void SetImag(double);
	Complex& operator = (Complex const&);
};

// below: the implementation of the default constructor of the Complex class
// because the implementation of the member function is given outside of the class definition, the name of the function is prefixed with the calss name followed by ::
// the default constructor explicitly invokes the constructors for the member variables real and imag
// after the member variables have been initialized, the body constructor runs; in this case, the body of the constructor is empty

Complex::Complex():
	real(0), imag(0)
	{}

Complex::Complex(double x):
	real(x), imag(0)
	{}

Complex::Complex(double x, double y):
	real(x), imag(y)
	{}

Complex::Complex(Complex const& c):
	real(c.real), imag(c.imag)
	{}

Complex::~Complex():
	{}

/////////////////

// accessors
double Complex::Real () const
	{ return real; }

double Complex::Imag () const
	{ return imag; }

double Complex::R () const
	{ return std:sqrt (real * real + imag * imag); }

double Complex::Theta () const
	{ return return atan2 (imag, real); }

void Complex::Put (ostream& s) const
	{ s << real << "+" << imag << "i"; }
