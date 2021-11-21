#pragma once

/*
	Inappropriate
*/
class CDataBaseInappropriate
{
public:

	CDataBaseInappropriate() {}

	~CDataBaseInappropriate() {}

	void getStepThree();

	void getStepFour();
};


/*
	Proper
*/
class CDataBase
{
public:

	CDataBase() {}

	~CDataBase() {}

	void run();

	void getStepThree();

	void getStepFour();


protected:
	virtual void getStepOne() = 0;
	virtual void getStepTwo() = 0;

};