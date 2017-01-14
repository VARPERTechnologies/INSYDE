#include "unit.h"

const double angRange = 180;

ec_gui::Unit::Unit() : MovilAgent()
{
    iniciarUnidad(Human, Blue, None, 100, 100, 0, 0);
}

ec_gui::Unit::Unit(PlayerType tj,
               PlayerColor cr,
               PlayerTeam eq,
               int vitalidadMaxima,
               int vitalidad,
               int energiaMaxima,
               int energy,
               double alcanceVisual,
               double rapidez) : MovilAgent(rapidez, alcanceVisual)
{
    iniciarUnidad(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy);
}

ec_gui::Unit::Unit(PlayerType tj,
               PlayerColor cr,
               PlayerTeam eq,
               int vitalidadMaxima,
               int vitalidad,
               int energiaMaxima,
               int energy) : MovilAgent()
{
    iniciarUnidad(tj, cr, eq, vitalidadMaxima, vitalidad, energiaMaxima, energy);
}


void ec_gui::Unit::iniciarUnidad(PlayerType tj, PlayerColor cr, PlayerTeam eq, int maxVitalidad, int vitalidad, int maxEnergy, int energy){
    const int barWidth = 20;

//    QPainterPath path;
////    path.lineTo(10,0);
//    path.addEllipse(QRectF(-10, -10, 20, 20));
//    setShape(path);
//    includeBars = false;

    checkCounter = 0;

    setBorderWidth(2);
    setPlayerType(tj);
    setUnitColor(cr);
    setEquipo(eq);

    QRectF rectMA = MovilAgent::boundingRect();
    prepareGeometryChange();
    setMaxHealth(maxVitalidad);
    setHealth(vitalidad);
    setHealthBarPos(rectMA.topLeft() + QPointF(rectMA.width()/2 - barWidth/2, - 20));
    setHealthBarWidth(barWidth);
    setHealthBarHeight(4);
    setVisibleHealthBar(true);

    setMaxEnergy(maxEnergy);
    setEnergy(energy);
    setEnergyBarPos(rectMA.topLeft() + QPointF(rectMA.width()/2 - barWidth/2, - 10));
    setEnergyBarWidth(barWidth);
    setEnergyBarHeitght(4);
    setVisibleEnergyBar(true);

    setAcceptHoverEvents(true);

    PlayerColor pc;
    for(int i = 0; i < 8; i++){
        pc = (PlayerColor)i;
        if(pc == getUnitColor()){
            diplomacias[pc] = Alied;
        }else{
            diplomacias[pc] = Enemy;
        }
    }
    MovingActuator *actMov = dynamic_cast<MovingActuator*>(getActuator("movement"));

    connect(actMov, SIGNAL(positionChanged(QPointF)), SLOT(checkAll(QPointF)));
//    connect(actMov, SIGNAL(llegoADestinoFinal(QPointF)), SLOT(lastCheckPointReached(QPointF)));
}

QPointF ec_gui::Unit::generateRandomPosition(double minValX, double maxValX, double minValY, double maxValY)
{
    //    int time = QTime::currentTime().msec();
//    struct timeval te;
//    struct timezone tz;
    //    tm *tim;
//    gettimeofday(&te, &tz);
    //    tim = localtime(&te.tv_sec);
    //    unsigned int time = clock();
//    qsrand(te.tv_usec);

    // TODO: Tiene que ser puesto aqui por problemas de generacion de numero aleatorio al que no consegui solucion
    qrand();
    if(minValX < maxValX && minValY < maxValY){
        double rndX = minValX + (maxValX - minValX) * double(qrand())/RAND_MAX;
        double rndY = minValY + (maxValY - minValY) * double(qrand())/RAND_MAX;
        return QPointF(rndX, rndY);
    }
    else{
        qWarning() << "Los parametros 0 y 2 deben ser menores que los parametros 1 y 3 respectivamente";
        return QPointF();
    }
}


QPointF ec_gui::Unit::generateRandomPosition(double module, double minAngle, double maxAngle)
{
//    int time = QTime::currentTime().msec();
//    struct timeval te;
//    struct timezone tz;
//    tm *tim;
//    gettimeofday(&te, &tz);
//    tim = localtime(&te.tv_sec);
//    unsigned int time = clock();
//    qsrand(te.tv_usec);

    minAngle = minAngle*M_PI/180;
    maxAngle = maxAngle*M_PI/180;

    //TODO: Tiene que ser puesto aqui por problemas de generacion de numero aleatorio al que no consegui solucion
    qrand();
    if(minAngle < maxAngle){
        Vector2D vec(float(module), float(minAngle + (maxAngle - minAngle) * double(qrand())/RAND_MAX));
//        double rndAng = minValX + (maxValX - minValX) * double(qrand())/RAND_MAX;
        return vec.toPointF();
    }
    else{
        qWarning() << "El parametro 1 debe ser menor que el parametro 2";
        return QPointF();
    }
}

QPointF ec_gui::Unit::generateRandomPosition(double module, double range)
{
    //TODO: Tiene que ser puesto aqui por problemas de generacion de numero aleatorio al que no consegui solucion
    qrand();
    double angAnt = getDirectionRads();
    double minAngle = angAnt - (range*M_PI/360);
    double maxAngle = angAnt + (range*M_PI/360);
    if(minAngle < maxAngle){
        Vector2D vec(float(module), float(minAngle + (maxAngle - minAngle) * double(qrand())/RAND_MAX));
        //        double rndAng = minValX + (maxValX - minValX) * double(qrand())/RAND_MAX;
        return vec.toPointF();
    }
    else{
        qWarning() << "Hay un error en el procesamiento";
        return QPointF();
    }
}

void ec_gui::Unit::deleteUnit()
{
//    setVisible(false);
//    setEnabled(false);
    scene()->removeItem(this);
    emit dead(this);
    disconnect();
    delete this;
}

QPointF ec_gui::Unit::generateNextValidPos()
{
    QPointF nextPos(0, 0);
    bool continua;
    QRectF escRect = scene()->sceneRect();
    int intentos = 0;
    do{
        if(intentos < 3){
            nextPos = pos() + generateRandomPosition(100, angRange);
            intentos++;
        }else{
            nextPos = pos() + generateRandomPosition(100, 0, 360);
        }
        continua = !((nextPos.x() > escRect.x()) && (nextPos.x() < escRect.x() + escRect.width()) && (nextPos.y() > escRect.y()) && (nextPos.y() < escRect.y() + escRect.height()));
    }while(continua);
    return nextPos;
}

void ec_gui::Unit::setHealthBarPos(const QPointF &pos)
{
    prepareGeometryChange();
    healthBar.setTopLeft(pos);
}

QPointF ec_gui::Unit::getHealthBarPos()
{
    return healthBar.topLeft();
}

void ec_gui::Unit::setEnergyBarPos(const QPointF &pos)
{
    prepareGeometryChange();
    energyBar.setTopLeft(pos);
}

QPointF ec_gui::Unit::getEnergyBarPos()
{
    return energyBar.topLeft();
}

void ec_gui::Unit::setEnergyBarWidth(double val)
{
    prepareGeometryChange();
    energyBar.setWidth(val);
}

double ec_gui::Unit::getEnergyBarWidth()
{
    return energyBar.width();
}

void ec_gui::Unit::setEnergyBarHeitght(double val)
{
    prepareGeometryChange();
    energyBar.setHeight(val);
}

double ec_gui::Unit::getEnergyBarHeight()
{
    return energyBar.height();
}

void ec_gui::Unit::setHealthBarWidth(double val)
{
    prepareGeometryChange();
    healthBar.setWidth(val);
}

double ec_gui::Unit::getHealthBarWidth()
{
    return healthBar.width();
}

void ec_gui::Unit::setHealthBarHeight(double val)
{
    prepareGeometryChange();
    healthBar.setHeight(val);
}

double ec_gui::Unit::getHealthBarHeight()
{
    return healthBar.height();
}

bool ec_gui::Unit::getVisibleEnergyBar() const
{
    if(useEnergy()){
        return visibleEnergyBar;
    }else{
        return false;
    }
}

void ec_gui::Unit::setVisibleHealthBar(bool b)
{
    prepareGeometryChange();
    visibleHealthBar = b;
}

bool ec_gui::Unit::getVisibleHealthBar() const
{
    return visibleHealthBar;
}

void ec_gui::Unit::setEnergy(int val)
{
    if(val <= maxEnergy){
        energy = val;
    }else{
        energy = maxEnergy;
        qWarning() << "La energia debe ser menor que la energia maxima. Se asigno la maxima energia";
    }
//    prepareGeometryChange();
    update();
}

int ec_gui::Unit::getEnergy()
{
    return energy;
}

void ec_gui::Unit::setMaxEnergy(int valmax)
{
    maxEnergy = valmax;
    update();
}

int ec_gui::Unit::getMaxEnergy()
{
    return maxEnergy;
}

void ec_gui::Unit::setUnitColor(PlayerColor col)
{
    colorUnidad = col;
    switch(colorUnidad){
        case Blue:
            setColor(QColor(0, 0, 255));
            break;
        case Red:
            setColor(QColor(255, 0, 0));
            break;
        case Green:
            setColor(QColor(0, 255, 0));
            break;
        case Yellow:
            setColor(QColor(255, 200, 0));
            break;
        case Orange:
            setColor(QColor(255, 80, 0));
            break;
        case Purple:
            setColor(QColor(255, 0, 255));
            break;
        case Brown:
            setColor(QColor(200, 127, 100));
            break;
        case Cyan:
            setColor(QColor(0, 230, 255));
    }
    update();
}

ec_gui::PlayerColor ec_gui::Unit::getUnitColor()
{
    return colorUnidad;
}

void ec_gui::Unit::setPlayerType(PlayerType tipo)
{
    tipoJugador = tipo;
}

ec_gui::PlayerType ec_gui::Unit::getPlayerType()
{
    return tipoJugador;
}

void ec_gui::Unit::setEquipo(PlayerTeam equipo)
{
    team = equipo;
}

ec_gui::PlayerTeam ec_gui::Unit::getEquipo()
{
    return team;
}

void ec_gui::Unit::setHealth(int vitalidad)
{
    if(vitalidad > 0 && vitalidad <= maxHealth){
        health = vitalidad;
        update();
    }else if(vitalidad <= 0){
        health = 0;
        deleteUnit();
    }else{
        health = maxHealth;
        update();
        qWarning() << "Salud actual excede la salud maxima. Se asigno la maxima salud";
    }
}

int ec_gui::Unit::getHealth()
{
    return health;
}

void ec_gui::Unit::incrementHealth(int increment)
{
    if(health + increment <= maxHealth){
        health += increment;
    }else{
        health = maxHealth;
    }
    update();
}

void ec_gui::Unit::decrementHealth(int decrement)
{
    if(health - decrement > 0){
        health -= decrement;
        update();
    }else{
        health = 0;
        deleteUnit();
    }
}

void ec_gui::Unit::setMaxHealth(int vitalidad)
{
    maxHealth = vitalidad;
    if(health > maxHealth){
        health = vitalidad;
    }
    update();
}

int ec_gui::Unit::getMaxHealth()
{
    return maxHealth;
}

bool ec_gui::Unit::isEnemy(Unit *un)
{
    return (getDiplomacyTo(un->getUnitColor()) == Enemy && un->getColor() != getColor() ? true : false);
}

void ec_gui::Unit::setDiplomacies(const QMap<PlayerColor, Diplomacy> &dip)
{
    diplomacias = dip;
}

QMap<ec_gui::PlayerColor, ec_gui::Diplomacy> ec_gui::Unit::getDiplomacies() const
{
    return diplomacias;
}

void ec_gui::Unit::setDiplomacyTo(const PlayerColor &pc, const Diplomacy &dip)
{
    if(pc == colorUnidad){
        qWarning() << "No puedes establecer la diplomacia hacia las unidades de tu mismo color (siempre seran aliados)";
    }else{
        diplomacias[pc] = dip;
    }
}

ec_gui::Diplomacy ec_gui::Unit::getDiplomacyTo(const PlayerColor &pc)
{
    return diplomacias[pc];
}

void ec_gui::Unit::setMode(Mode mod)
{
    currentMode = mod;
    switch(currentMode){
        case Stand:
            break;
        case Search:
            startSearchMode();
            break;
        case Flee:
            startFleeMode();
            break;
        case Attack:
//            startAttackMode();
            break;
    }
}

ec_gui::Mode ec_gui::Unit::getMode()
{
    return currentMode;
}

void ec_gui::Unit::startSearchMode()
{
    clearPoints();

    addPoint(generateNextValidPos());

    currentMode = Search;
}

void ec_gui::Unit::startFleeMode()
{
    clearPoints();
    addPoint(0, 0);
    currentMode = Flee;
}

QRectF ec_gui::Unit::boundingRect() const
{
    QPainterPath path;
//    if(isSelected() || isUnderMouse()){
        if(getVisibleHealthBar()){
            path.addRect(healthBar);
        }
        if(getVisibleEnergyBar()){
            path.addRect(energyBar);
        }
//        canPaint = true;
//    }
    path.addRect(MovilAgent::boundingRect());
    return path.controlPointRect();
}

void ec_gui::Unit::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    MovilAgent::paint(painter, option, widget);

    QRectF actBar;
    double percent;

    painter->save();
    if(option->state & (QStyle::State_Selected | QStyle::State_MouseOver)) {
        if(getVisibleHealthBar()){
            percent = health/maxHealth;
            painter->setPen(Qt::NoPen);
            if(percent > 0.5){ //si la salud esta por encima del 50%
                painter->setBrush(QColor(255*2*(1 - percent), 255, 0));
            }else{
                painter->setBrush(QColor(255, 2*255*percent, 0));
            }
            actBar = healthBar;
            actBar.setWidth(percent * healthBar.width());
            painter->drawRect(actBar);
            painter->setPen(Qt::black);
            painter->setBrush(Qt::NoBrush);
            painter->drawRect(healthBar);
        }
        if(getVisibleEnergyBar()){
            percent = energy/maxEnergy;
            actBar = energyBar;
            actBar.setWidth(percent * energyBar.width());
            painter->setPen(Qt::NoPen);
            painter->setBrush(QColor(0, 0, 255));
            painter->drawRect(actBar);
            painter->setPen(Qt::black);
            painter->setBrush(Qt::NoBrush);
            painter->drawRect(energyBar);
        }
//        canPaint = false;
    }
    painter->restore();
    //    painter->drawRect(boundingRect());
}

//void Unit::lastCheckPointReached(QPointF point)
//{
//    switch(currentMode){
//        case Stand:
//            break;
//        case Attack:
//            break;
//        case Flee:
//            break;
//        case Search:
//            clearDestinos();
//            agregarDestino(pos() + generateRandomPosition(100, 0, 360));
//            break;
//    }
//}

void ec_gui::Unit::checkPointReached(QPointF point)
{
    switch(currentMode){
        case Stand:
            break;
        case Attack:
            break;
        case Flee:
            if(point == QPoint(0,0)){
                startSearchMode();
            }
            break;
        case Search:
            clearPoints();

            addPoint(generateNextValidPos());
            break;
    }
}

void ec_gui::Unit::checkAll(QPointF pt)
{
    Q_UNUSED(pt);

    if(checkCounter > 20){
        Unit *unit;
        VisionSensor *vs = dynamic_cast<VisionSensor*>(getSensor("vision"));
        QList<Agent*> agents = vs->getAgents();
        int numAgents = agents.count();
        switch(currentMode){
            case Stand:
                break;
            case Flee:
                for(int i = 0; i < numAgents; i++){
                    if((unit = dynamic_cast<Unit*>(agents[i]))){
                        if(isEnemy(unit)){
                            break;
                        }else{
                            startSearchMode();
                            break;
                        }
                    }
                }
                break;
            case Attack:
            case Search:
                QList<QGraphicsItem*> items = scene()->items(vs->getCoverArea());
//                QGraphicsObject *obj;
                QList<Unit*> enemyList;
                QList<Unit*> aliesList;

                PheromoneItem* pheromone;
                QList<PheromoneItem*> pheromoneList;

                int itemCount = items.count();

                for(int i = 0; i < itemCount; i++){
                    if((unit = dynamic_cast<Unit*>(items[i]))){
                        if(isEnemy(unit)){
                            enemyList.append(unit);
                        }else{
                            aliesList.append(unit);
                        }
                    }else if((pheromone = dynamic_cast<PheromoneItem*>(items[i]))){
                        pheromoneList.append(pheromone);
                    }
                }
                if(enemyList.count() > 0){
                    emit enemySighted(aliesList, enemyList);
                    emit enemySighted(enemyList);
                }
                if(pheromoneList.count() > 0){
                    emit pheromoneDetected(pheromoneList);
                }
                break;
        }
        checkCounter = 0;
    }else{
        checkCounter++;
    }
}

void ec_gui::Unit::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    MovilAgent::hoverMoveEvent(event);
    update();
}
