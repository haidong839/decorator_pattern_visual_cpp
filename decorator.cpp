// decorator.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <cliext/list> 
using namespace std;
using namespace System;



ref class Shape abstract
{ 
public:
	Shape(void)	{;}		
	virtual void draw() = 0;  
};

ref class Rectangle : Shape
{  
public:
	Rectangle(void){;}
	~Rectangle(void){;}
	virtual void draw() override 
	{  
		Console::WriteLine("Shape: Rectangle"); 		
	}  
	
};

ref class Circle : Shape
{  
public:
	Circle(void){;}
	~Circle(void){;}
	virtual void draw() override 
	{  
		Console::WriteLine("Shape: Circle"); 
	}   
};

ref class ShapeDecorator abstract : Shape  {
public:
	Shape^ decoratedShape;
	ShapeDecorator(void){;}
	ShapeDecorator(Shape^ decoratedShape){
		this->decoratedShape = decoratedShape;
	}

	virtual void draw() override {
		decoratedShape->draw();
	}	
};

ref class RedShapeDecorator :  ShapeDecorator {
private:
	void setRedBorder(Shape^ decoratedShape){
		Console::WriteLine("Border Color: Red");
	}
public:
	RedShapeDecorator(){;}
	RedShapeDecorator(Shape^ decoratedShape) {
		__super::decoratedShape = decoratedShape;		
	}

	virtual void draw() override {
		decoratedShape->draw();	       
		setRedBorder(decoratedShape);
	} 
};

int _tmain(int argc, _TCHAR* argv[])
{
	Shape^ circle = gcnew Circle();
	Shape^ redCircle = gcnew RedShapeDecorator(gcnew Circle());

	Shape^ redRectangle = gcnew RedShapeDecorator(gcnew Rectangle());
	Console::WriteLine("Circle with normal border");
	circle->draw();

	Console::WriteLine("\nCircle of red border");
	redCircle->draw();

	Console::WriteLine("\nRectangle of red border");
	redRectangle->draw();
	Console::ReadLine();
	return 0;
}

