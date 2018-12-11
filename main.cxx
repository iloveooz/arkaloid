
	#include <SFML/Graphics.hpp>
	#include <time.h>
	
	bool isCollide(sf::Sprite s1, sf::Sprite s2) {
		return s1.getGlobalBounds().intersects(s2.getGlobalBounds());
		
	}
	
	int main() {
		
		srand(time(NULL));
		
		sf::RenderWindow app(sf::VideoMode(520, 450), "Alkakoid");
		app.setFramerateLimit(60);
		
		sf::Texture t1, t2, t3, t4, t5, t6, t7, t8;
		
		t1.loadFromFile("images/block01.png");
		t2.loadFromFile("images/background.jpg");
		t3.loadFromFile("images/ball.png");
		t4.loadFromFile("images/paddle.png");
		
		t5.loadFromFile("images/block02.png");
		t6.loadFromFile("images/block03.png");
		t7.loadFromFile("images/block04.png");
		t8.loadFromFile("images/block05.png");
		
		sf::Sprite sBackground(t2), sBall(t3), sPaddle(t4);
		
		sPaddle.setPosition(300, 440);
		sBall.setPosition(300, 300); 
		
		sf::Sprite block[1000];
		
		int n = 1;
		
		for (int i = 1; i <= 10; i++) 
			for (int j = 1; j <= 10; j++) {
				switch (rand() % 10 + 1) {
					case 2: 
						block[n].setTexture(t5); break;
					case 3: 
						block[n].setTexture(t6); break;
					case 4: 
						block[n].setTexture(t7); break;
					case 5: 
						block[n].setTexture(t8); break;
        			default: 
						block[n].setTexture(t1);
				}

				
				
				if ((rand() % 5) == 0) block[n].setTexture(t5);
				if ((rand() % 5) == 1) block[n].setTexture(t6);
				if ((rand() % 5) == 2) block[n].setTexture(t7);
				if ((rand() % 5) == 3) block[n].setTexture(t8);
								
				block[n].setPosition(i * 43, j * 20);
				n++;
			}
		
		double dx = 4, dy = 3;
		
		while(app.isOpen()) {
			sf::Event e;
			while (app.pollEvent(e)) {
				if (e.type == sf::Event::Closed) 
					app.close();
			}
		
		sBall.move(dx, 0);
		
		for (int i = 0; i < n; i++) 
			if (isCollide(sBall, block[i])) {
				block[i].setPosition(-100, 0);
				dx = -dx;
			}
		
		sBall.move(0, dy);
		for (int i = 0; i < n; i++) 
			if (isCollide(sBall, block[i])) {
				block[i].setPosition(-100, 0);
				dy = -dy;
			}
		
		
		sf::Vector2f b = sBall.getPosition();
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) sPaddle.move(6, 0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) sPaddle.move(-6, 0);
		
		if (isCollide(sPaddle, sBall)) dy = -(rand() % 5 + 2);
		
		if (b.x < 0 || b.x > 520) dx = -dx;
		if (b.y < 0 || b.y > 450) dy = -dy;
		
		app.clear();
		app.draw(sBackground);
		app.draw(sBall);
		app.draw(sPaddle);
		
		for (int i = 0; i <= n; i++) 
			app.draw(block[i]);
		
		
		app.display();	
		}
		
		// some changes
		
		
		return 0;
	}
	
	
	
