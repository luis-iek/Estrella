# Dibujar una estrella usando el simulador Turtlesim de ROS.
Este proyecto permite que el simulador Turtlesim dibuje una estrella de 5 puntas.

Inicialmente se debe crear un directorio que será el espacio de trabajo (workspace) de la aplicación, dentro de ese directorio se debe crear otro directorio cuyo nombre sea "src" en el cual irán los elementos necesarios para la ejecución del proyecto ("CMakeLists.txt", "package.xml", "estrella.cpp" y "estrella.launch").

Los archivos "CMakeLists.txt" y "package.xml" contienen las librerías necesarias para la correcta ejecución. El archivo "estrella.cpp" es el código fuente de este proyecto escrito en C++. El archivo "estrella.launch" contiene la información necesaria para ejecutar el proyecto desde una sola terminal, ya que si no estuviese deberían usarse tres terminales distintas, una para el núcleo ROS, otra para crear el nodo de turtlesim y otra para el proyecto en sí.

El paquete (package) del proyecto se llama "estrella".

# Ejecutar el proyecto.

Inicialmente se debe abrir una terminal y acceder al directorio del workspace, una vez allí se procede a compliar el proyecto con el comando:

  $ catkin_make
  
Una vez compilado el proyecto se debe introducir el siguiente comando:

  $ source devel/setup.bash
  
Ahora que ya está compilado el proyecto, se llama al launcher (archivo launch) para ejecutar el proyecto, en la terminal:

  $ roslaunch estrella estrella.launch
  
Con esto comienza la ejecución de la aplicación y al finalizar se debe ver una estrella de 5 puntas en la pantalla.