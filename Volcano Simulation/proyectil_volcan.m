x = -pi:0.1:-1.04;
y = cos(x)+1;
plot(x,y)
hold on
x = 1.04:0.1:pi;
y = cos(x)+1;
plot(x,y)
hold on
plot([-1.04,1.04],[1.5,1.5])
hold on
xlabel('x')
ylabel('y')
title('Volcán: Tiro parabólico')

for i = 1:3
    if i>1
        delete(findobj(ax,'type', 'text'))
    end
    ax = gca;
    v0 = input('Ingrese velocidad inicial: ');
    ang = input('Ingrese el angulo que forma con la horizontal: ');
    angr = deg2rad(ang);
    v0x = v0*cos(angr);
    v0y = v0*sin(angr);
    dt = 0.009;
    g = 9.8;
    m = 17.6;%[kg] masa de la roca
    pair = 1.84;%[kg/m3] densidad aire
    radio = 0.09;
    area = pi*(radio^2);
    h0 = 1.5;
    volumen = (4/3)*pi*(radio^3);
    Cd = input('Ingrese la resistencia del aire: ');
    b = (1/2)*pair*Cd*area;
    xn = 0;
    yn = h0;
    x = xn
    y = yn
    Xn = xn-v0x*dt;
    Yn = yn-(v0y*dt)-(g*dt^2);
    comet(xn,yn)
while y>=0
    YN = (2*yn-Yn)-(((yn-Yn)/dt)^2)*(b/m)*(dt^2)-(g*(dt^2));
    XN = (2*xn-Xn)-(((xn-Xn)/dt)^2)*(b/m)*(dt^2);
    comet(XN,YN)
    x = XN
    y = YN
    t = x/v0x;
    v = v0-g*t
    Yn = yn; yn = YN;
    Xn= xn; xn = XN;
end
equismx = {'Xmax',XN};
text(-3,2,equismx,ax);
ymax = ((v0^2)*(sin(angr))^2)/(2*(g))+h0;
ymx = {'Ymax', ymax};
text(-3,1.5,ymx,ax);
sprintf("Volcan: velocidad inicial -->%f", v0)
sprintf("Volcan: altura inicial -->%f", h0)
sprintf("Volcan: angulo de elevacion -->%f", ang)
sprintf("Volcan: velocidad inicial en x -->%f", v0x)
sprintf("Volcan: velocidad inicial en y -->%f", v0y)
sprintf("Volcan: diferencial de tiempo -->%f", dt)
sprintf("Volcan: gravedad -->%f", g)
sprintf("Volcan: masa del objeto -->%f", m)
sprintf("Volcan: densidad del aire -->%f", pair)
sprintf("Volcan: radio del objeto -->%f", radio)
sprintf("Volcan: area del objeto -->%f", area)
sprintf("Volcan: coeficiente de arrastre -->%f", Cd)
sprintf("Volcan: densidad del aire -->%f", pair)
pause(3)
end

