#ifndef UVSIM_ICLI
#define UVSIM_ICLI

class ICLI {
public:
	virtual void launch() = 0;
protected:
	Memory* drive;
};

#endif