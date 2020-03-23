

class PixData {
public:
	PixData() {
	funcid = 9;
	tid = 9;
	posx = 9;
	posy = 9;
	width = 9;
	height = 9;
	}

	virtual ~PixData(void) {}

	int funcid;
	int tid;
	int posx;
	int posy;
	int width;
	int height;
};


//PixData::~PixData() {
//}

/*
int PixData::getFuncID() {
	return funcid;
}

int PixData::getTypeID() {
	return tid;
}

int PixData::getPosX() {
	return posx;
}

int PixData::getPosY() {
	return posy;
}

int PixData::getWidth() {
	return width;
}

int PixData::getHeight() {
	return height;
}

*/
