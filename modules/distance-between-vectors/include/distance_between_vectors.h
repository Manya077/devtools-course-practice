// Copyright 2020 Vladislav Golubev

#ifndef MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#define MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
#include <vector>

class Metrics {
 protected:
    std::vector<float> fst;
    std::vector<float> sec;

 public:
    Metrics();
    Metrics(const std::vector<float>& _fst,
            const std::vector<float>& _sec);
    virtual ~Metrics() = 0;

    std::vector<float> getFirst() const;
    std::vector<float> getSecond() const;

    void setFirst(const std::vector<float>& _fst);
    void setSecond(const std::vector<float>& _sec);
    void setBoth(const std::vector<float>& _fst,
                 const std::vector<float>& _sec);

    virtual double getMetrics() const = 0;
};

class L1 : public Metrics {
 public:
    L1() : Metrics() {}
    L1(const std::vector<float>& _fst,
       const std::vector<float>& _sec) : Metrics(_fst, _sec) {}
    ~L1() = default;
    double getMetrics() const final;
};

class L2 : public Metrics {
 public:
    L2() : Metrics() {}
    L2(const std::vector<float>& _fst,
       const std::vector<float>& _sec) : Metrics(_fst, _sec) {}
    ~L2() = default;
    double getMetrics() const final;
};

class L3 : public Metrics {
 public:
    L3() : Metrics() {}
    L3(const std::vector<float>& _fst,
       const std::vector<float>& _sec) : Metrics(_fst, _sec) {}
    ~L3() = default;
    double getMetrics() const final;
};

class L4 : public Metrics {
 public:
    L4() : Metrics() {}
    L4(const std::vector<float>& _fst,
       const std::vector<float>& _sec) : Metrics(_fst, _sec) {}
    ~L4() = default;
    double getMetrics() const final;
};

class LInf : public Metrics {
 public:
    LInf() : Metrics() {}
    LInf(const std::vector<float>& _fst,
         const std::vector<float>& _sec) : Metrics(_fst, _sec) {}
    ~LInf() = default;
    double getMetrics() const final;
};

#endif  // MODULES_DISTANCE_BETWEEN_VECTORS_INCLUDE_DISTANCE_BETWEEN_VECTORS_H_
