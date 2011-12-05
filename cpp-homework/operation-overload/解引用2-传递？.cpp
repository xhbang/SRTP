//传送功能
#include <iostream.h>


//mpg,take_off,swim(virtual func),default copy
class Vechile{
	Vechile * hostVechile;
public:
	virtual int mpg(){
		return 0;
	}
	virtual void takeoff(){
		hostVechile->takeoff();
	}
	virtual void swim(){
		hostVechile->swim();
	}
	Vechile(Vechile * p){
		hostVechile=p;
	}
};

//mpg,byplane(construct)
class byPlane:public Vechile{
public:
	int mpg(){
		return 5;
	}
	//一个不太懂的东西
	byPlane(Vechile *p):Vechile(p)
	{}

};

//mpg,byBoat(consturct)
class byBoat:public Vechile{
public:
	int mpg(){
		return 10;
	}
	byBoat(Vechile *p):Vechile(p)
	{}
};

//construct,decon,takeoff,swim,operator->,currentMode
class SeaPlane: public Vechile{
	Vechile *boat,*plane,*current;
public:
	SeaPlane():Vechile(0){
		current=boat=new byBoat(this);			//这是什么意思
		plane= new byPlane(this);
	}
	~SeaPlane(){
		delete boat;
		delete plane;
	}
	void takeoff(){
		current=plane;
	}
	void swim(){
		current=boat;
	}

	//关键：重载->,返回基类的指针
	Vechile * operator ->(){
		return current;
	}
};

int main(){
	SeaPlane sea_plane;
	cout<<sea_plane->mpg()<<endl;
	sea_plane->takeoff();
	cout<<sea_plane->mpg()<<endl;
	sea_plane->swim();
	cout<<sea_plane->mpg()<<endl;
	return 0;
}