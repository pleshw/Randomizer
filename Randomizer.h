
/*
	Gerador de números aleatórios ou simulador de dado não viciado.
	Deve ser compilado com a flag `-std=c++11`.
*/
#ifndef PLESHW_RANDOM
#define PLESHW_RANDOM

	#include <random>
	#include <map>

	typedef long ElementoAnalisado;
	typedef size_t Ocorrencias;
	// Hash table com {Key: Elemento} {Value: Numero de ocorrencias}
	typedef std::map< ElementoAnalisado, Ocorrencias > Simulacao;

	class Randomizer
	{

	private: 
		// Cria um objeto para um dispositivo de randomização para gerar a seed se possível.
		std::random_device _randomizador;

		// Cria um gerador que recebe uma função para retornar.
		std::default_random_engine _gerador;

		// Guarda a seed que vai gerar os números retornados.
		unsigned int _seed;

		// Define o intervalo minimo e maximo a ser dado para a distribuição.
		double _minimo;
		double _maximo;

		//Define o intervalo dos numéros aleatórios
		std::uniform_real_distribution<double> _distribuicao;

	public:
		// Construtor com um range passado por parâmetro.
 		Randomizer( double min = 1.0 , double max = 6.0 ): 
	 		_minimo  { min }, 
	 		_maximo  { max+1 }, // Max inclusive
 			_randomizador { /* void */ },
 			_seed { _randomizador() },
 			_gerador { _seed },
	 		_distribuicao { _minimo, _maximo }
		{ /* Alocação e declarações extras se necessário. */ }


 		// Retorna um número real aleatório dentro do range.
 		double GetRandom ( void ) { return _distribuicao(_gerador); }

 		// Retorna um número inteiro aleatório dentro do range.
 		long GetRandomInt ( void ) { return std::floor( _distribuicao(_gerador) ); }

 		// Retorna um array com o resultado do teste de n dados jogados aleatoriamente.
 		virtual Simulacao Test ( size_t n )
 		{
			Simulacao tmp;
			for( int i = _minimo; i < _maximo; i++ )
		    	tmp[i] = 0;
			for( int i = 0; i < n; i++ )
		    	tmp[getRandomInt()]++;
		    return tmp;
 		}
	};

#endif