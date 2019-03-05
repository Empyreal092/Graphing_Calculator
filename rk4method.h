#ifndef RK4METHOD_H
#define RK4METHOD_H

#include <QWidget>
#include "odesolverbase.h"

namespace Ui {
class RK4method;
}

class RK4method : public ODESolverBase{
    Q_OBJECT

public:

    explicit RK4method(ODESolverBase *parent = nullptr);

    ~RK4method() override;

    void makepoints() override;
};

#endif // RK4METHOD_H
