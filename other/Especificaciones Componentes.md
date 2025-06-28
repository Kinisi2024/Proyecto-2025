## Batería 9V (Alimentación Recargable):

 * Función principal: Es la fuente de energía de todo el sistema. Suministra la electricidad necesaria para que todos los demás componentes electrónicos funcionen.

 * Detalle: Al ser recargable, permite su reutilización, lo cual es eficiente y económico.
##  Motorreductores (conectados a un eje):

* Función principal: Son los encargados del movimiento del carro. Transforman la energía eléctrica en movimiento rotatorio.

 * Detalle: La presencia de un "reductor" (engranajes internos) en el motor reduce la velocidad de giro pero aumenta el torque, lo que es ideal para mover un vehículo. Al estar conectados a un eje, aseguran que ambas ruedas (si es un sistema de dos ruedas motrices) giren a la misma velocidad, permitiendo un avance recto y controlado.

## 3. Sensores Ultrasónicos:

* Función principal: Son los "ojos" del carro. Emiten ondas de sonido de alta frecuencia (ultrasonido) y miden el tiempo que tardan en regresar después de rebotar en un objeto.
  
 * Detalle: Esta información de tiempo de vuelo se utiliza para calcular la distancia a los obstáculos (como las paredes de la pista), permitiendo que el carro detecte su entorno y evite colisiones.

## Servomotor:

* Función principal: Permite la dirección del carro. Controla el giro de las ruedas delanteras (o el mecanismo de dirección) para que el carro pueda "cruzar" o cambiar de dirección.
  
 * Detalle: A diferencia de un motor convencional que gira continuamente, un servomotor puede posicionarse en un ángulo específico y mantenerlo, lo que lo hace ideal para sistemas de dirección precisos.

## 5. Driver de Motor L298N Mini:

* Función principal: Es el "músculo" que controla los motorreductores. Recibe las señales de la tarjeta programable (Arduino Nano) y proporciona la corriente necesaria para que los motores se muevan en la dirección y con la velocidad deseada. También es responsable de dar el "torque" o la fuerza de giro a los motores.
  
 * Detalle: Un microcontrolador como el Arduino Nano no puede suministrar directamente la alta corriente que necesitan los motores, por lo que el L298N actúa como un intermediario o amplificador de potencia. Permite controlar la dirección de giro (adelante/atrás) y, en algunos casos, la velocidad (mediante PWM).

## 6. Tarjeta Programable Arduino Nano:

* Función principal: Es el "cerebro" del carro. Aquí resides el código o programa que le da la inteligencia al vehículo.
  
   * Programación: Es donde se cargan las instrucciones lógicas para interpretar las señales de los sensores ultrasónicos, decidir cómo mover los motores (a través del L298N) y cómo posicionar el servomotor para la dirección.
     
   * Suministro de energía (en parte): Si bien la batería principal es la fuente de energía general, el Arduino Nano distribuye y regula la energía para sus propios componentes y puede alimentar pequeñas cargas, aunque el L298N es el encargado de la potencia de los motores principales.
     
   * Conexiones: Actúa como el centro de control donde se conectan todos los demás componentes para interactuar entre sí.
     
En resumen, cada componente juega un papel crucial y se complementa con los demás para que tu carro autónomo pueda moverse, detectar obstáculos y navegar por la pista de forma independiente.