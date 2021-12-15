#include <gtest/gtest.h>
#include <Automaton.h>

std::string random_string(size_t x) {
  std::string res = "";
  for (size_t size = rand() % x; size > 0; --size) {
    res.push_back('0' + (rand() % x));
  }
  return res;
}

TEST(random_tests, litte_graph) {
  srand(1234);
  for (size_t counter = 2000; counter > 0; -- counter) {
    std::cout << counter << std::endl;
    size_t v = 1 + (rand() % 10);
    size_t start = rand() % v;
    vector<Edge> edges;
    edges.clear();
    for (size_t e = rand() % (v*v); e > 0; --e) {
      edges.emplace_back(rand()%v, rand()%v, random_string(3));
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
    if (counter >= 0) {
      Automaton a(v, edges, start, finish);
      Automaton b(a);
      b.deleteEmptyEdges();
      a.minimize();
      ASSERT_EQ(Automaton::IsSameRandom(a, b), true);
    }
  }
}

TEST(random_tests, big_graph) {
  srand(2345);
  for (size_t counter = 200; counter > 0; -- counter) {
    std::cout << counter << std::endl;
    size_t v = 1 + (rand() % 30);
    size_t start = rand() % v;
    vector<Edge> edges;
    edges.clear();
    for (size_t e = rand() % (v*5); e > 0; --e) {
      edges.emplace_back(rand()%v, rand()%v, random_string(3));
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
    if (counter >= 0) {
      Automaton a(v, edges, start, finish);
      Automaton b(a);
      b.deleteEmptyEdges();
      a.minimize();
      ASSERT_EQ(Automaton::IsSameRandom(a, b), true);
    }
  }
}