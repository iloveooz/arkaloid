
	#include <SFML/Graphics.hpp>
	#include <time.h>
	
	
	int main() {
		sf::RenderWindow app(sf::VideoMode(520, 450), "Alkakoid");
		app.setFramerateLimit(60);
		
		sf::Texture t1, t2, t3, t4, t5;
		
		t1.loadFromFile("images/block01.png");
		t2.loadFromFile("images/background.jpg");
		t3.loadFromFile("images/ball.png");
		t4.loadFromFile("images/paddle.png");
		
		sf::Sprite sBackground(t2), sBall(t3), sPaddle(t4);
		
		sPaddle.setPosition(300, 440);
		sBall.setPosition(300, 300); 
		
		sf::Sprite block[1000];
		
		int n = 0;
		
		for (int i = 1; i <= 10; i++) 
			for (int j = 1; j <= 10; j++) {
				block[n].setTexture(t1);
				block[n].setPosition(i * 43, j * 20);
				n++;
			}
		
		while(app.isOpen()) {
			sf::Event e;
			while (app.pollEvent(e)) {
				if (e.type == sf::Event::Closed) 
					app.close();
			}
		
		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);
		
		for (int i = 0; i <= n; i++) 
			app.draw(block[i]);
		
		
		app.display();	
		}
		
		return 0;
	}
	
	
	
