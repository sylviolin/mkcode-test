

class PixData {
public:
	PixData() {
	funcid = 0;
	tid = 0;
	posx = 0;
	posy = 0;
	width = 0;
	height = 0;
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
