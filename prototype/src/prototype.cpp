//============================================================================
// Name        : prototype.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : prototype ���� ����
//============================================================================

#include <iostream>
#include <list>
#include <iterator>
#include <map>

using namespace std;

class Position{
public:
	Position(){}
	Position(int x, int y){
		x_=x; y_=y;
	}

private:
	int x_, y_;
};

class Graphic{
public:
	virtual void Draw(Position& pos)=0;
	virtual Graphic* Clone() =0;
};

class Triangle: public Graphic{
public:
	void Draw(Position& pos){}
	Graphic* Clone(){return new Triangle(*this)};
};

class Rectangle: public Graphic{
public:
	void Draw(Position& pos){}
	Graphic* Clone(){return new Rectangle(*this)};
};

class GraphicComposite:public Graphic{
	void Draw(Position& pos){ }
	Graphic* Clone(){
		GraphicComposite *pGraphicComposite = new GraphicComposite(*this);
		list<Graphic *>::iterator iter1;
		list<Graphic *>::iterator iter2;
		iter2=pGraphicComposite->components_.begin();
		for(iter1=components_.begin(); iter1!=components_.end(); iter1++){
			Graphic*pNewGraphic=(*iter1)->Clone();
			*iter2=pNewGraphic;
			iter2++;
		}
		return pGraphicComposite;
	}

private:
	list<Graphic *> components_;
};

class Document{
public:
	void Add(Graphic* pGraphic){ }
};

class Mouse{
public:
	bool IsLeftButtonPushed(){
		static bool isPushed =false;
		//GUI �Լ� Ȱ�� Left Button ���� üũ
		isPushed=!isPushed;
		return isPushed;
	}

	Position GetPosition(){
		Position pos;
		//GUI �Լ� Ȱ�� ���� ���콺 ��ġ �ľ�
		return pos;
	}
};

Mouse _mouse;

class GraphicEditor{
public:
	void AddNewGraphics(Graphic* pSelected){
		Graphic* pObj = pSelected->Clone();
		while(_mouse.IsLeftButtonPushed()){
			Position pos=_mouse.GetPosition();
			pObj->Draw(pos);
		}
		curDoc_.Add(pObj);
	}
private:
	Document curDoc_;
};

class Palette{
public:
	Palette(){
		Graphic* pGraphic = new Triangle;
		items_[1]=pGraphic;

		pGraphic=new Rectangle;
		items_[2]=pGraphic;

	}

	void RegisterNewGraphic(Graphic* pGraphic){
		items_[items_.size()+1]=pGraphic;
	}

	Graphic* GetSelectedObj(){
		return items_[GetItemOrder()];
	}

	int GetItemOrder(){
		int i=1;
		Position curPos=_mouse.GetPosition();
		//���� ���콺 ��ġ�� ���° �׸��� �����ϴ��� �Ǻ�
		return i;
	}

private:
	map<int, Graphic*> items_;
};

int main() {
	Palette palette;
	GraphicEditor ged;

	ged.AddNewGraphics(palette.GetSelectedObj());
	return 0;
}