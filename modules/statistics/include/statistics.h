// Copyright 2020 Maximova Irina & Kukushkina Ksenia

#ifndef MODULES_STATISTICS_INCLUDE_STATISTICS_H_
#define MODULES_STATISTICS_INCLUDE_STATISTICS_H_

#include <map>
#include <vector>

typedef std::map<int, double> Map;

class Distribution {
 public:
  Distribution();
  explicit Distribution(Map rand_var);
  Distribution(const Distribution& s);

  Map getRandomVar() const;
  void setRandomVar(Map rand_var);
  std::vector<int> getValue() const;
  std::vector<double> getProbability() const;

  Distribution& operator=(const Distribution& s);
  bool operator==(const Distribution& s) const;
  bool operator!=(const Distribution& s) const;

  double expectedValue() const;
  double dispersion() const;
  double moment(int order, double a) const;

 private:
  int checkProbability(Map rand_var) const;
  Map random_var;
};

#endif  // MODULES_STATISTICS_INCLUDE_STATISTICS_H_
