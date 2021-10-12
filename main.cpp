#include <iostream>
#include <vector>
#include "Automaton.h"
#include <cassert>


std::string random_string() {
  std::string res = "";
  for (size_t size = rand() % 3; size > 0; --size) {
    res.push_back('0' + (rand() % 3));
  }
  return res;
}

int main() {
  srand(1234);
  for (size_t counter = 2000; counter > 0; -- counter) {
    std::cout << counter << std::endl;
    size_t v = 1 + (rand() % 10);
    size_t start = rand() % v;
    vector<Edge> edges;
    edges.clear();
    for (size_t e = rand() % (v*v); e > 0; --e) {
      edges.emplace_back(rand()%v, rand()%v, random_string());
    }
    vector<size_t> finish;
    for (size_t i = 0; i < v; ++i) {
      if (rand() % 2 == 0) {
        finish.emplace_back(i);
      }
    }
    if (finish.size() == 0) {
      finish.emplace_back(0);
    }
    if (counter == 1963) {
      Automaton a(v, edges, start, finish);
      Automaton b(a);
      a.print();
      b.print();
      b.deleteEmptyEdges();
      a.deleteEmptyEdges();
      a.deleteMoreThanOneLetterEdges();
      a.print();
      //b.print();
      assert(Automaton::IsSameRandom(a, b));
    }
  }
  return 0;

  srand(1234);
  for (size_t counter = 2000; counter > 0; -- counter) {
    std::cout << counter << std::endl;
    size_t v = 1 + (rand() % 10);
    size_t start = rand() % v;
    vector<Edge> edges;
    edges.clear();
    for (size_t e = rand() % (v*v); e > 0; --e) {
      edges.emplace_back(rand()%v, rand()%v, random_string());
    }
    vector<size_t> finish;
    for (size_t i = 0; i < v; ++i) {
      if (rand() % 2 == 0) {
        finish.emplace_back(i);
      }
    }
    if (finish.size() == 0) {
      finish.emplace_back(0);
    }
    Automaton a(v, edges, start, finish);
    Automaton b(a);
    if (counter == 1927) {
      std::cout << "here" << std::endl;
      a.print();
      b.print();
      a.deleteEmptyEdges();
      b.deleteEmptyEdges();
      a.print();
      b.print();
      return 0;
      //assert(Automaton::IsSameRandom(a, b));
      //a.deleteMoreThanOneLetterEdges();
      //assert(Automaton::IsSameRandom(a, b));
      //a.determinize();
      //assert(Automaton::IsSameRandom(a, b));
      //a.makeFull();
      //assert(Automaton::IsSameRandom(a, b));
      //a.deleteUnreachableVertices();
      //assert(Automaton::IsSameRandom(a, b));
      //a.sortEdges();
      //assert(Automaton::IsSameRandom(a, b));
      //a.minimize();
      //assert(Automaton::IsSameRandom(a, b));
    }
    //b.deleteEmptyEdges();
    //a.minimize();
    //assert(Automaton::IsSameRandom(a, b));
  }

  return 0;

  srand(time(0));
  size_t v = 5;
  size_t start = 0;
  vector<Edge> edges = {{0, 1, "a"},
                        {0, 2, ""},
                        {2, 1, "aba"},
                        {2, 3, "ab"},
                        {3, 4, "a"},
                        {3, 1, "a"},
                        {1, 4, ""},
                        {2, 2, ""},
                        {3, 3, "b"},
                        {4, 2, ""}};
  vector<size_t> finish = {1};
  Automaton a(v, edges, start, finish);
  Automaton b(a);
  b.deleteEmptyEdges();
  a.print();
  a.minimize();
  a.print();
  assert(Automaton::IsSameRandom(a, b));
  return 0;
  {
    srand(time(0));
    size_t v = 2;
    size_t start = 0;
    vector<Edge> edges = {{0, 0, "b"},
                          {0, 1, "a"},
                          {1, 0, "b"},
                          {1, 1, "a"}};
    vector<size_t> finish = {1};
    Automaton a(v, edges, start, finish);
    Automaton b(a);
    a.print();
    a.minimize();
    a.print();
    std::cout << Automaton::IsSameRandom(a, b);
    return 0;
  }
}
