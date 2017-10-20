#ifndef _GUI_
#define _GUI_

#pragma once
#include <map>
#include <SFML\Graphics.hpp>
#include <string>
#include "Widget.h"
#include "GUIButton.h"
#include <iostream>
#include "GUIConsole.h"
#include "GUIList.h"
#include "GUIInput.h"
#include "GUILabel.h"
class GUI
{
	std::map<std::string, Widget*> widgets;// contains widget 
	Widget* holder; // holds current clicked widget
	int Res_x, Res_y; // window resolution
public:
    //add widget
	void AddWidget(const std::string string, Widget* widget);
	
    
	Widget* GetWidget(const std::string string)
	{
		return widgets[string];
	}
	//Widget* GetButtom
	void draw(sf::RenderWindow * window) 
	{
		for (auto& e : widgets) 
		{
			window->draw(*e.second);
		}
		
	}
	//check if mouse cursor is over the widget
	void check(int x,int y) 
	{
		for (auto& e : widgets) 
		{
			e.second->check(x,y);
		}
	}
	//check if the mouse was pressed over widget
	bool clicked(int x,int y) 
	{
		for (auto& e : widgets) 
		{
			if(e.second->clicked(x,y))
			{
				holder = e.second;
				return true;
			}
		}
	}
	//return value of vidget
	sf::String const& GetString()
	{
		return holder->GetString();
	}
	void Clear() 
	{
		widgets.clear();
	}
	void DeleteWidget(std::string string)
	{
		auto temp = widgets.find(string);
		widgets.erase(temp);
	}
	GUI();
	GUI(int x,int y):Res_x(x),Res_y(y){}
	~GUI();
};

#endif // _GUI_




