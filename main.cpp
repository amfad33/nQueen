#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>

int main()
{
	std::cout<<"Hi,To end type 0!"<<std::endl;
	while(true){
		std::cout<<"please print n. you can choose 0<n<=16"<<std::endl;
		int n;
		std::cin>>n;
		if(n>0 && n<=16){
			sf::RenderWindow window(sf::VideoMode(std::max(n*45,100), std::max(n*45,100)), "nQueen");
			sf::RectangleShape box(sf::Vector2f(40,40));
			box.setFillColor(sf::Color::Blue);

			int* mem = new int[n];
			int top=0;
			bool calc =true;

			for(int i=0;i<n;i++)
				mem[i]=-1;

			while (window.isOpen())
			{
				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();
				}

				if(calc){
					mem[top]++;
					//std::cout<<"new mem["<<top<<"] is :"<<mem[top]<<std::endl;
					bool bad=false;
					if(mem[top]==n){
						mem[top]=-1;
						top--;
						if(top==-1)
							calc=false;
						bad=true;
					}
					if(!bad){
						bool isIt= true;
						for(int k=0;k<top;k++)
							if((k+mem[k]==mem[top]+top) || (k-mem[k]==top-mem[top]) || (mem[k]==mem[top]))
								isIt=false;
						//std::cout<<"isIt is "<<isIt<<std::endl;
						if(isIt){
							top++;
							if(top==n)
								calc=false;
						}
					}
				}

				window.clear(sf::Color(200,200,200));
				for(int i=0;i<n;i++)
					for(int j=0;j<n;j++){
						box.setPosition(i*42+5,j*42+5);
						if(mem[i]==j)
							box.setFillColor(sf::Color::Green);
						else
							box.setFillColor(sf::Color::Blue);
						window.draw(box);
					}
				window.display();
			}
		}else if(n==0)
			break;
		else{
			std::cout<<"Wrong n, try again ..."<<std::endl;
		}
	}

    return 0;
}
