#include <iostream>
#include <memory>

class Constantes{
	private:
		float const_ela, const_amort;
	public:
		Constantes(float k, float b);
		void set_const(float k, float b);
		float get_ela();
		float get_amort();
};

Constantes::Constantes(float k, float b){
	const_ela = k;
	const_amort = b;
}

void Constantes::set_const(float k, float b){

	const_ela = k;
	const_amort = b;

}

float Constantes::get_ela(){
	return const_ela;
}
float Constantes::get_amort(){
	return const_amort;
}

class Variaveis{
	private:
		float massa, posicao, velocidade, aceleracao;
	public:
		Variaveis(float m, float p, float v, float a);
		void set_var(float m, float p, float v, float a);
		void set_massa(float m);
		void set_pos(float p);
		void set_vel(float v);
		void set_ace(float a);
		float get_massa();
		float get_pos();
		float get_vel();
		float get_ace();
};

Variaveis::Variaveis(float m, float p, float v, float a){
	massa = m;
	posicao = p;
	velocidade = v;
	aceleracao = a;
}

void Variaveis::set_var(float m, float p, float v, float a){
	massa = m;
	posicao = p;
	velocidade = v;
	aceleracao = a;
}

void Variaveis::set_massa(float m){
	massa = m;
}
void Variaveis::set_pos(float p){
	posicao = p;
}
void Variaveis::set_vel(float v){
	velocidade = v;
}
void Variaveis::set_ace(float a){
	aceleracao = a;
}

float Variaveis::get_massa(){
	return massa;
}
float Variaveis::get_pos(){
	return posicao;
}
float Variaveis::get_vel(){
	return velocidade;
}
float Variaveis::get_ace(){
	return aceleracao;
}

class View{
	public:
		View();
		void render(float pos, int tempo);
		
};

void View::render(float pos, int tempo){
	int printar;
	printar = (int) 200*pos/10 + 200;
	std::cout << printar << ',' << tempo << std::endl;
}

class Simulacao{
	private:
		std::shared_ptr<Variaveis> var;
		std::shared_ptr<Constantes> constantes;
		std::shared_ptr<View> view;
		const float T = 0.01;
	public:
		Simulacao(std::shared_ptr<Variaveis> v, std::shared_ptr<Constantes> con);
		float Aceleracao();
		void Init();
};

Simulacao::Simulacao(std::shared_ptr<Variaveis> v, std::shared_ptr<Constantes> con){
	var = v;
	constantes = con;
}

float Simulacao::Aceleracao(){
	return (-(constantes->get_ela()*var->get_pos())-(constantes->get_amort()*var->get_vel()))/var->get_massa();
}

void Simulacao::Init(){

	for (int i=0; i*T<10; i++){
		var->set_ace(Aceleracao());
		var->set_vel(var->get_vel() + var->get_ace()*T);
		var->set_pos((var->get_pos() + var->get_vel()*T + var->get_ace()*T*T/2));
		if(var->get_pos() > 0) view->render(var->get_pos(), i*T);
		else view->render(-var->get_pos(), i*T); 
	}
}



int main(){
	std::shared_ptr<Constantes> con (new Constantes(1, 1));
	std::shared_ptr<Variaveis> var (new Variaveis(1, 10, 0, 0));
	Simulacao s(var, con);
	s.Init();
}

