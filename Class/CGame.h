#ifndef CLASS_CGAME_H_
#define CLASS_CGAME_H_

class CGame : public CSceneManager{

	virtual void Init(SDL_Surface * screen);
	virtual void Update();
	virtual void Render();
	virtual void Exit();
};

#endif /* CLASS_CGAME_H_ */
