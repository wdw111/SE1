#pragma once
class GameTreeNode
{
private:
	int level;
	int Eval_value;
	char state[3][3];//state
public:
	GameTreeNode(void);
	~GameTreeNode(void);
	void FillBoard();
	void Setlevel(int l){level=l;};//lelvel=l
	void SetEval_value(int e){Eval_value=e;};//Eval_value=e
	int Getlevel(){return level;};//return level
	int GetEval_value(){return Eval_value;};//return Eval_value
	char (*Getstate())[3]{return state;};//return state
};

