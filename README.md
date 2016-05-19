# TADs Lista 
#### (*Vector*, *List* e *Forward List*)

### tópicos abordados:

- **Apresentação**;  
- **A implementação**;
- **Como compilar e executar**
- **Testes realizados**;
- **Bugs**;
- **Observações**;
- **Sobre o grupo**;

##### status do projeto: **v 0.0.7**  

#### Apresentação:
Nesse projeto temos como objetivo simular o comportamento de três das 
estrututuras de dados do STL (Vector, List e Forward_list), para tal
usamos das TADs Lista simples, lista duplamente encadeada e lista 
encadeada, respectivamente. Até a versão atual apenas o Vector e
o Forward_list estão implementados em sua maior parte.
    
As implementações foram feitas em C++ e estão adaptadas para receberem
tipos variados de dados.    
#### A implementação:  
  
  Os seguintes arquivos são pertencentes a implementação do vector:
  
  1) **Vector/src/main.hpp** : Contém o codigo da função main
  2) **Vector/include/Forward_list.hpp** :  Contém a classe Vector.
  3) **Vector/src/Forward_list.inl** : Contém a implentação dos métodos da classe Vector.
  4) **Vector/src/iterator.inl** :  Possui a implementação dos metodos das classes Iterator e Const_Iterator.
  
  E os seguintes arquivos são pertencentes a implementação do Forward_list:
  
  1) **Forward_list/src/main.hpp** : Contém o codigo da função main
  2) **Forward_list/include/Forward_list.hpp** :  Contém a classe Forward_list.
  3) **Forward_list/src/Forward_list.inl** : Contém a implentação dos métodos da classe Forward_list.
  4) **Forware_list/src/iterator.cpp** :  Possui a implementação dos metodos das classes Iterator e Const_Iterator.
  
### Como compilar e executer
  Para compilar o código é indicado o compilador g++ pois foi o utilizado na compilação do codigo.
  Assumindo que os requerimentos/conselhos estejam sendo seguidos para compilar o codigo do vector usando o g++ é necessario utilizar o seguinte comando no terminar dentro da pasta Vector:
  
    g++ -std=c++11 -I include src/main.cpp -o bin/Vector
  
  Já para compilar o código de Forware_list os requerimentos/conselhos são os mesmos, com exeção da pasta em que o terminar deve estar aberto. A pasta é a Forward_list e o comando do g++ é:
  
    g++ -std=c++11 -I include src/main.cpp -o bin/Forward_list
  
### Testes realizados:
  
  Os testes realizados foram básicos de funcionamento. Podem não refletir algum eventual bug que testes profundos revelariam.
    
### Bugs:
  
  O codigo ainda não está finalizado. A classe referente a lista duplamente encadeada não foi implementada. Entretando o que foi escrito está funcional, isso não significa que o código está perfeito ou livre de erros. Provavelmente existe muito codigo a ser otimizado. O repositorio está indicado no final desse documento.

### Observações:

  O codigo será postado no GitHub dos dois integrantes desse grupo e certamente será finalizado. O projeto é muito interessante e pode ser utilizado como base para diversos projetos futuros.

  Esse projeto se encontra no Git Hub no link:  
  
  -GitHub de Nalbert Gabriel Melo Leal:
   https://github.com/nalbertg/TAD-List
  
  -GitHub de Yuri Reinaldo:
   https://github.com/Yuri-wrlk/Assignments 

### Sobre o grupo:
    
- **Aluno**: Nalbert Gabriel Melo Leal;
- **GitHub**: github.com/nalbertg ;
- **email pessoal**: nalbertrn@yahoo.com.br;
- **email acadêmico/profissional**: nalbertg@outlook.com;
  

- **Aluno**: Yuri Reinaldo;
- **GitHub**:  https://github.com/Yuri-wrlk ;
- **email**: yurinatal@hotmail.com ;
    
