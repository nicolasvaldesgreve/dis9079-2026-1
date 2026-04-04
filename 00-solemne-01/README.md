# solemne-01

la solemne-01 ha sido accidentada debido a chascarros computacionales del profesore aarón montoya.

las primeras mitades de clase han sido teóricas e históricas sobre computación con un enfoque en microcontroladores y protocolos inalámbricos, y las demostraciones con el protocolo MQTT han tenido muchos problemas de puertos y permisos, lo siento!

como parte de mi labor estaré reparando este primer mes accidentado, para que cuando lleguemos a la solemne-02 y al examen esto sea solamente un recuerdo de lo difícil que es hacer una comunicación inalámbrica, y que nos permita apreciar lo aprendido durante el semestre.

## equipos

como curso dividimos 32 estudiantes en 11 grupos.

- grupo-01:
  - Monserrat-Paredes
  - sofiacartes
  - vxlentiinaa
- grupo-02
  - magdalenabalart
  - jesumirandaa
  - ccarlabelenn
- grupo-03
  - antokiaraa
  - tomascatri
  - angel-udp
- grupo-04
  - AlegriaColoma
  - antolavalle
  - catasal
- grupo-05
  - felipecaurapan
  - Camila-Parada
  - paredesvania
- grupo-06
  - arevalourra
  - isipm08
  - nicolasvaldesgreve
- grupo-07
  - josefa-kristina
  - DebSkar
  - cristobalvergarasilva
- grupo-08
  - brauliofigueroa2001
  - Luisaatoro9
- grupo-09
  - Guilleibanez
  - marlensoto-lab
  - marcezm
- grupo-10
  - agustinaaceituno
  - TODO: ignacio campos
  - AntFuentealba
- grupo-11
  - benjaminalvarez21
  - Anaysval

## instrucciones

en grupos llenar cada carpeta, les ruego NO cambiar los nombres de las carpetas y los archivos, para que el proceso de evaluación sea más fluida.

## pauta

la nota tiene 1 punto base más 6 puntos evaluados.

- los 3 primeros puntos son criterios grupales.
- los 3 siguientes puntos son criterios individuales.

este es el desglose:

1. grupal - valentía de tomar este curso nuevo y resiliencia ante las dificultades.

2. grupal - usar código un experimento de enviar información entre dos placas distintas conectadas a dos computadores distintos, vía Adafruit IO.

3. grupal - documentación textual en github de todo el trabajo y los aprendizajes del proyecto realizado con Adafruit IO.

4. individual - bitácoras individuales de las sesiones de clases, esto se evaluará en las subcarpetas que tiene cada estudiante.

5. individual - investigación individual de tutoriales de Adafruit IO, documentar textual y visualmente (pantallazos) proceso de instalación en tu computador, aprendizajes, dificultades.

6. individual - investigación en bitácora personal sobre alguna artista, diseñadora o producto que usa electrónica o computación inalámbricas, por ejemplo: la obra de rafael lozano-hemmer, de lauren lee mccarthy, de kyle mcdonald.

para los puntos 5. y 6. se evaluará la profundidad de la investigación, la claridad de la documentación y el esfuerzo demostrado en la investigación. se escribe en los archivos `persona-01.md`,  `persona-02.md` y `persona-03.md`, donde cada estudiante debe plasmar la investigación realizada por y durante la solemne-01.

## tutoriales para la solemne-01

aquí van tutoriales técnicos sobre cómo usar Adafruit IO para la solemne-01, los revisaremos también el lunes en clase, pero también feliz de conversar vía discord en cualquier momento en el canal de `#solemne-01`, les pido eso sí etiquetarme a mí @montoyamoraga y a @mateo.

### sobre Adafruit IO

usaremos Adafruit IO para enviar información entre dos placas distintas conectadas a dos computadores distintos, vía Adafruit IO.

- tutorial de Adafruit IO: <https://learn.adafruit.com/series/adafruit-io-basics>

### sobre instalación en tu computadora

instalaremos la biblioteca de Adafruit IO para Arduino.

esta biblioteca está disponible para su lectura en el repositorio <https://github.com/adafruit/Adafruit_IO_Arduino>.

para instalarla en nuestro software `Arduino IDE`, debemos seguir los siguientes pasos:

- abrir el software `Arduino IDE`.
- ir al menú lateral izquierdo, al tercer ícono de `Library Manager`.
- en el buscador de la parte superior derecha, escribir `Adafruit IO Arduino`.
- seleccionar la biblioteca `Adafruit IO Arduino` y hacer clic en el botón `Install`. en abril 2026 la versión más reciente es la `4.3.4`, les recomiendo instalar esa o una más reciente.
- al momento de instalar, el software te preguntará si quieres instalar las otras bibliotecas que necesita `Adafruit IO Arduino` para funcionar correctamente. es muy importante que ACEPTES y SÍ las instales. es tan importante que lo escribí en mayúsculas.

### sobre la cuenta de Adafruit IO

- ingresar a <https://io.adafruit.com/> y crear una cuenta gratuita.
- te pido por favor usar tu correo udp, para poder identificarte fácilmente en el curso.
- usen una cuenta gratuita,no es necesario pagar por esta plataforma para el curso.
- al hacer inicio de sesión, en la esquina superior derecha hay un ícono de una llave con fondo amarillo, si haces click en ella podrás ver tus credencias.
- es muy importante que NO compartas tus credenciales, que NO las subas a github. si quieres compartirlas con tu grupo, hazlo por privado, por ejemplo a través de un mensaje por correo electrónico. si las subes a github, cualquiera podría usarlas y eso podría generar problemas de seguridad para tu cuenta.

### sobre la cuenta que usaremos

yo pagué por el plan anual como parte de mi labor de enseñanza del curso, y les compartiré mis claves para que puedan usar mi cuenta durante el semestre.

las publicaré en discord, en el canal de `#solemne-01`, para que puedan acceder a ellas y usarlas durante el semestre. por favor, usen estas claves con responsabilidad y no las compartan con nadie fuera del curso, ni tampoco las suban a github.

### sobre cómo enviar info a la nube desde tu placa

les subí a cada carpeta de cada grupo de la solemne-01 un código de ejemplo para enviar info a Adafruit IO.

este código tiene 2 archivos:

1. archivo principal `.ino` con el codigo y muchisimos comentarios que traduje para explicarles en español lo que hace cada sección.
2. archivo de apoyo `config.h` donde hay que reemplazar 4 valores:

- `IO_USERNAME` con el nombre de usuario de tu cuenta de Adafruit IO.
- `IO_KEY` con la clave de tu cuenta de Adafruit IO.
- `WIFI_SSID` con el nombre de tu red wifi.
- `WIFI_PASS` con la contraseña de tu red wifi.

este código es un ejemplo básico para enviar información a Adafruit IO, y es un buen punto de partida para que puedan empezar a experimentar con esta plataforma. les recomiendo que lo prueben y lo modifiquen para entender mejor cómo funciona.

si usan mi usuario y clave, les recomiendo que modifiquen el nombre del feed al que envían la información, para evitar que todos los grupos estén enviando información al mismo feed y se genere un caos de datos.

también pueden usar su propia cuenta de Adafruit IO, si prefieren, pero recuerden que deben mantener sus credenciales en privado y no compartirlas ni subirlas a github.

### sobre cómo actualizar el firmware de tu placa

lo más probable es que cuando corras el código, y lo subas a tu placa, te aparezca un mensaje de error que diga algo como:

```txt
21:23:38.769 -> .....................................................conectando a Adafruit IOFirmware version 0.3.0 is outdated. Latest version is 0.5.2
21:24:06.104 -> Please upgrade the WiFiS3 firmware!
```

esto significa que el firmware de tu placa está desactualizado y no es compatible con la versión de la biblioteca de Adafruit IO que estás usando.

para actualizar el firmware de tu placa, debes seguir los siguientes pasos:

1. en Arduino IDE ir al menú `Tools` y seleccionar `Firmware Updater`.
2. en la ventana emergente seleccionar tu placa.
3. hacer click en el botón `Check for Updates` para verificar si hay una actualización disponible.
4. si hay una actualización disponible, hacer click en el botón `Update Firmware` para iniciar el proceso de actualización, en mi caso tenía en mi placa la versión `0.5.2` y la actualización la hice a la más reciente en abril 2026, la `0.6.0`.
5. esperar a que el proceso de actualización se complete, esto puede tardar varios minutos, así que ten paciencia y no desconectes tu placa durante el proceso.
6. una vez que la actualización se complete, tu placa ya no tendrá el código que habías subido.
7. vuelve a subirlo, y revisa que ya no te aparezca el mensaje de error sobre el firmware desactualizado.
