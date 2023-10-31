#include <iostream>
#include <Windows.h>

using namespace std;

class Squer{
public:
    int pos[4][2];
    char character = '#';

    void setPos(int a[2],int b[2],int c[2],int d[2]){
        pos[0][0] = a[0];
        pos[0][1] = a[1];
        pos[1][0] = b[0];
        pos[1][1] = b[1];
        pos[2][0] = c[0];
        pos[2][1] = c[1];
        pos[3][0] = d[0];
        pos[3][1] = d[1];
    }
    void setCharacter(char c='#'){
        character = c;
    }
    int getPoint(int a,int b){
        return pos[a][b];
    }


    void moveAll(int x=0,int y=0){
        // X move
        for(int i=0;i<x;i++){
            for(int j=0;j<4;j++){
                pos[j][0] ++;
            }
        }

        // Y move
        for(int i=0;i<y;i++){
            for(int j=0;j<4;j++){
                pos[j][1] ++;
            }
        }
    }

    void movePoint(int x=0,int y=0,int point=0){
        int pointX = getPoint(point,0);
        int pointY = getPoint(point,1);

        pos[point][0] += x;
        pos[point][1] += y;
    }
};

class Pixel{
public:
    int pos[2];
    char character;

    void setPos(int x=0,int y=0){
        pos[1]=x;
        pos[0]=y;
    }

    void setCharacter(char c='#'){
        character = c;
    }
};

class Line{
public:
    int startPos[2];
    int endPos[2];
    char character;

    //setters
    void setStartPos(int x=0,int y=0){
        startPos[0]=x;
        startPos[1]=y;
    }
    void setEndPos(int x=0,int y=0){
        endPos[0]=x;
        endPos[1]=y;
    }
    void setCharacter(char c='#'){
        character = c;
    }

    //Fn
    void moveAll(int x=0,int y=0){
        startPos[0]+=x;
        endPos[0]+=x;

        startPos[1]+=y;
        endPos[1]+=y;
    }
    void movePoint(int x=0,int y=0,int point=0){

        switch (point)
        {
        case 0:
            setStartPos(startPos[0] += x,startPos[1] += y);
            break;
        case 1:
            setEndPos(endPos[0] += x,endPos[1] += y);
            break;
        default:
            break;
        }
    }
};

class Screen{
public:
    int x=50,y=20;
    char dotsArray[20][50];

    void init(char character) {
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 50; j++) {
				dotsArray[i][j] = character;
			}
		}
	}

    void print() {
		for (int i = 0; i < y; i++) {
			for (int j = 0; j < x; j++) {
				cout << dotsArray[i][j];
			}
			cout << '\n';
		}
	}


    //Draw
    void drawPixel(Pixel px){
        int x = px.pos[0];
        int y = px.pos[1];
        dotsArray[x][y] = px.character;
    }

    void drawLine(Line l){
        int sx = l.startPos[0];
        int sy = l.startPos[1];
        int ex = l.endPos[0];
        int ey = l.endPos[1];

        //Swap if right to left draw

        int i =0;
        while(sx!=ex || sy!=ey){
            Pixel startPx;
            Pixel endPx;
            startPx.setCharacter(l.character);
            endPx.setCharacter(l.character);

            startPx.setPos(sx,sy);
            endPx.setPos(ex,ey);

            i%2==0 ? drawPixel(startPx) : drawPixel(endPx);

            if(i%2==0){
                if(sx!=ex&&sy!=ey){
                    sx<ex ? sx++ : sx--;
                    sy<ey ? sy++ : sy--;
                }else if(sx!=ex){
                    sx<ex ? sx++ : sx--;
                }else if(sy!=ey){
                    sy<ey ? sy++ : sy--;
                }
            }else{
                if(sx!=ex&&sy!=ey){
                    sx>ex ? ex++ : ex--;
                    sy>ey ? ey++ : ey--;
                
                }else if(sx!=ex){
                    sx>ex ? ex++ : ex--;
                }else if(sy!=ey){
                    sy>ey ? ey++ : ey--;
                }
            }

            i++;
        }

        Pixel px;
        px.setCharacter(l.character);
        px.setPos(sx,sy);
        drawPixel(px);
    }

    void drawSquer(Squer sq){
        int a = sq.getPoint(0,0);
        for(int i=0;i<4;i++){
            int a = sq.getPoint(i,0);
            int b = sq.getPoint(i,1);
            int c = i==3 ? sq.getPoint(0,0):sq.getPoint(i+1,0);
            int d = i==3 ? sq.getPoint(0,1):sq.getPoint(i+1,1);
            
            Line l = createLine(a,b,c,d,sq.character);
            drawLine(l);
        }
    }
    // Create
    Line createLine(int startX,int startY,int endX,int endY,char character='#'){
        Line line;
        line.setCharacter(character);
        line.setStartPos(startX,startY);
        line.setEndPos(endX,endY);

        return line;
    }

    Squer createSquer(int ax,int ay,int bx,int by,int cx,int cy,int dx,int dy,char character='+'){
        Squer sq;
        int a[2] = {ax,ay};
        int b[2] = {bx,by};
        int c[2] = {cx,cy};
        int d[2] = {dx,dy};

        sq.setPos(a,b,c,d);
        sq.setCharacter(character);

        return sq;
    }
};

int main(){
    Screen scr;
    scr.init('.');

    Squer sq = scr.createSquer(0,0,5,0,5,5,0,5,'@');

    sq.moveAll(15,6);
    sq.movePoint(2,-2,0);
    sq.movePoint(-2,-2,1);
    sq.movePoint(-5,0,3);
    sq.movePoint(5,0,2);

    scr.drawSquer(sq);

    scr.print();
}