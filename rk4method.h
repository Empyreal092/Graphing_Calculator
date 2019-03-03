#ifndef RK4METHOD_H
#define RK4METHOD_H

#include <QWidget>
#include "eulermethod.h"

namespace Ui {
class RK4method;
}

class RK4method : public EulerMethod{
    Q_OBJECT

public:

    explicit RK4method(EulerMethod *parent = nullptr);

    ~RK4method() override;

    void makepoints() override;
};

#endif // RK4METHOD_H
