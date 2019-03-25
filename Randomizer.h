
/*
	Gerador de números aleatórios ou simulador de dado não viciado.
	Deve ser compilado com a flag `-std=c++11`.
*/
#ifndef PLESHW_RANDOM
#define PLESHW_RANDOM

	#include <random>
	#include <map>

	typedef long ElementInAnalysis;
	typedef size_t Occurrence;

	// Hash table com {Key: Elemento} {Value: Numero de ocorrencias}
	typedef std::map< ElementInAnalysis, Occurrence > Simulation;

	class Randomizer
	{

	private: 
		// Define o intervalo minimo e maximo a ser dado para a distribuição.
		double _min;
		double _max;

		//Define o intervalo dos numéros aleatórios
		std::uniform_real_distribution<double> _range;

		// Cria um objeto para um dispositivo de randomização para gerar a seed se possível.
		std::random_device _trueRandom;

		// Guarda a seed que vai gerar os números retornados.
		unsigned int _seed;

		// Cria um gerador que recebe uma função para retornar.
		std::default_random_engine _generator;

	public:
		// Construtor com um range passado por parâmetro.
 		Randomizer( double min = 1.0 , double max = 6.0 ): 
	 		_min  { min },
	 		_max  { max+1 }, // Max inclusive
	 		_range { _min, _max },
 			_trueRandom { /* void */ },
 			_seed { _trueRandom() },
 			_generator { _seed }
		{ /* Alocação e declarações extras se necessário. */ }

 		// Propriedades.
 		double min( void ) { return _min; }
 		double max( void ) { return _max; }
 		unsigned int seed( void ) { return _seed; }

 		// Retorna um número real aleatório dentro do range.
 		double GetRandom ( void ) { return _range(_generator); }

 		// Retorna um número inteiro aleatório dentro do range.
 		long GetRandomInt ( void ) { return std::floor( _range(_generator) ); }

 		// Retorna um array com o resultado do teste de n dados jogados aleatoriamente.
 		virtual Simulation Test ( size_t n )
 		{
			Simulation tmp;
			for( double i = _min; i < _max; i++ )
		    	tmp[i] = 0;
			for( double i = 0; i < n; i++ )
		    	tmp[GetRandomInt()]++;
		    return tmp;
 		}
	};

#endif