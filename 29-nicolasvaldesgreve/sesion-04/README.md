# sesion-04

lunes 30 marzo 2026

# Apuntes 30/03

Para la clase Aarón trajo un router de tp-link el cual estará conectado a un computador raspberry que estará siempre activo!! el computador siempre tendrá la misma IP (192.168.0.100). Mateo escribió "ssh raspi@192.168.0.100" y eso es tocar la puerta del computador, en donde te preguntará si te quieres conectar, y luego te pide una contraseña. Con ayuda de tigerVNC puedes entrar al computador y ver un renderizado de lo que hay dentro

sudo: su (super user, admin) do (hacer) + rm  (remove) rf (recursivamente, force) = sudo rm rf = eliminar todo de manera recursiva a la fuerza, es decir, matar el computador.

+ Cualquier persona que envia, debe hacerlo con un topic en específico, al igual que cualquier persona que recibe tiene que tener un topic en espec+ifico sino no se va a conectar
+ El puerto 1883 es el que más se usa en mqtt, pero se puede usar otro.
+ username e ID no son lo mismo 
+ -c correr en mosquitto
+ -v moquitto piensa en voz alta

---

Se intentó hacer el ejercicio de enviar y recibir mensajes mediante el arduino con mqtt, pero hubieron problemas y se pudo lograr enviar mensajes pero no se recibían, por lo que se intentó arreglar pensando que era porque el Username y el ID eran lo mismo, pero al editarlo siguió sin funcionar, razón por la cual se utilizó inteligencia artifical para buscar soluciones pero luego de muchos intentos, tampoco funcionó.

Mosquitto nos falló, por lo que se está tratando de hacer el ejercicio con otro protocolo, que en éste caso es UDP (no se llama así por Diego Portales)

- Protocolo UDP (user datagram protocol): Éste protocolo también sirve para enviar mensajes, pero no le importa si éstos llegan o no, por lo que no es bueno para enviar audio ya que se necesita algo constante y preciso.
