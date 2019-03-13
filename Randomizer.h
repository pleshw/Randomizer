
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
		std::random_device Randomizador;

		// Cria um gerador que recebe uma função para retornar.
		std::default_random_engine Gerador;

		// Guarda a seed que vai gerar os números retornados.
		unsigned int Seed;

		// Define o intervalo minimo e maximo a ser dado para a distribuição.
		double Minimo;
		double Maximo;

		//Define o intervalo dos numéros aleatórios
		std::uniform_real_distribution<double> Distribuicao;

	public:
		// Construtor com um range passado por parâmetro.
 		Randomizer( double min = 1.0 , double max = 6.0 ): 
	 		Minimo  { min }, 
	 		Maximo  { max+1 }, // Max inclusive
 			Randomizador { /* void */ },
 			Seed { Randomizador() },
 			Gerador { Seed },
	 		Distribuicao { Minimo, Maximo }
		{ /* Alocação e declarações extras se necessário. */ }


 		// Retorna um número real aleatório dentro do range.
 		double getRandom ( void ) { return Distribuicao(Gerador); }

 		// Retorna um número inteiro aleatório dentro do range.
 		long getRandomInt ( void ) { return std::floor( Distribuicao(Gerador) ); }

 		// Retorna um array com o resultado do teste de n dados jogados aleatoriamente.
 		Simulacao test ( size_t n )
 		{
 			Simulacao tmp;
 			for( int i = Minimo; i < Maximo; i++ )
		    	tmp[i] = 0;
		    for( int i = 0; i < n; i++ )
		    	tmp[getRandomInt()]++;
		    return tmp;
 		}
	};

#endif






// CODIGO TESTE E QUE VALE NOTA NO EXERCICIO.





// #include <iostream>

// int main(){
    
//     Randomizer r;
    
//     Simulacao EscopoDeTestes;
//     size_t NumeroDeTestes = 0;
    
//     // Testando 5 casos.
//     NumeroDeTestes = 5;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;
    
//     // Testando 100 casos.
//     NumeroDeTestes = 100;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;

//     // Testando 1000 casos.
//     NumeroDeTestes = 1000;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;

//     // Testando 10000 casos.
//     NumeroDeTestes = 10000;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;

//     // Testando 100000 casos.
//     NumeroDeTestes = 100000;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;    
        
//      // Testando 100000 casos.
//     NumeroDeTestes = 100000;
//     EscopoDeTestes = r.test( NumeroDeTestes );
    
//     std::cout << "Numero de testes da simulacao a seguir: " << NumeroDeTestes << std::endl;
//     for (auto& x: EscopoDeTestes)
//         std::cout << x.first << " ocorreu: " << x.second << " vezes ou seja " << 100*x.second/NumeroDeTestes << "% do total." << std::endl;
//     std::cout << std::endl << std::endl;
    
// }