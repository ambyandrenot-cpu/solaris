# SOLARIS

Simulation solaire interactive C++17 / Qt 6 / QML.

## Architecture

`SolarCalculator` contient le modèle astronomique (position apparente, déclinaison et angle horaire). `SimulationClock` fournit une horloge non bloquante pilotée par `QTimer`. `Sun` encapsule l’état affiché. `SolarSystemController` coordonne ces composants et expose leurs propriétés à QML. L’interface est limitée à la présentation et aux commandes.

Le calcul utilise une approximation NOAA basée sur le jour julien, la longitude, la déclinaison et l’équation du temps. Le lever/coucher conventionnel est −0,833°; l’API d’événements est prévue dans `SolarCalculator`. La précision attendue est de l’ordre de quelques minutes, pas une éphéméride de précision.

## Compilation Windows

Installer Qt 6 (modules Core, Gui, Quick, Quick Controls 2, Test) et CMake, puis depuis un terminal Qt :

```powershell
cmake -S . -B build -G Ninja
cmake --build build
ctest --test-dir build --output-on-failure
build\SOLARIS.exe
```
