#include <string>

struct Edge {
  std::size_t from;
  std::size_t to;
  std::string cost;

  Edge(std::size_t from_, std::size_t to_, const std::string& cost_): from(from_), to(to_), cost(cost_) {}
  Edge(std::size_t from_, std::size_t to_, std::string&& cost_): from(from_), to(to_), cost(std::move(cost_)) {}
};
