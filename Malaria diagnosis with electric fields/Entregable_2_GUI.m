%Equipo 2:

%Jorge Daniel Cruz Case A01634536

%Vanessa Méndez Palacios A01639925

%Luis Paulo Flores Arzate A01275194



%GUI Construida con la función Guide de MatLab

function varargout = Entregable_2_GUI(varargin)

% Edit the above text to modify the response to help Entregable_2_GUI
    
% Last Modified by GUIDE v2.5 25-Apr-2021 10:44:07

% Begin initialization code - DO NOT EDIT
gui_Singleton = 1;
gui_State = struct('gui_Name',       mfilename, ...
                   'gui_Singleton',  gui_Singleton, ...
                   'gui_OpeningFcn', @Entregable_2_GUI_OpeningFcn, ...
                   'gui_OutputFcn',  @Entregable_2_GUI_OutputFcn, ...
                   'gui_LayoutFcn',  [] , ...
                   'gui_Callback',   []);
if nargin && ischar(varargin{1})
    gui_State.gui_Callback = str2func(varargin{1});
end

if nargout
    [varargout{1:nargout}] = gui_mainfcn(gui_State, varargin{:});
else
    gui_mainfcn(gui_State, varargin{:});
end
% End initialization code - DO NOT EDIT


% --- Executes just before Entregable_2_GUI is made visible.
function Entregable_2_GUI_OpeningFcn(hObject, eventdata, handles, varargin)
handles.output = hObject;
guidata(hObject, handles);


% --- Outputs from this function are returned to the command line.
function varargout = Entregable_2_GUI_OutputFcn(hObject, eventdata, handles) 
varargout{1} = handles.output;




% --- Executes on slider movement.
function distancia_Callback(hObject, eventdata, handles)
rotate3d 
cla;

m=5;
dm=0.3;
[xx, yy]=meshgrid(-m:dm:m);
zz = xx.*0;

dis = get(handles.distancia,'Value');
dy = get(handles.longitud, 'Value');
dy2 = dis/2;
dx = get(handles.longitudx, 'Value');
dx2 = dis/2;

%Atributos básicos
vertice = 0.5;
ancho = 0.5;
largo = (dx+0.5)*2;
posX = dis/2;

%Vertices y caras de la placa positiva
                        % x               y          z
vertices = [-vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 1
            -vertice*ancho-posX   vertice*largo  -vertice; %Vertice 2
             vertice*ancho-posX   vertice*largo  -vertice; %Vertice 3
             vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 4
            -vertice*ancho-posX  -vertice*largo   vertice; %Vertice 5
            -vertice*ancho-posX   vertice*largo   vertice; %Vertice 6
             vertice*ancho-posX   vertice*largo   vertice; %Vertice 7
             vertice*ancho-posX  -vertice*largo   vertice];%Vertice 8
         
caras = [1 5 8 4; %Cara 1
         1 5 6 2; %Cara 2
         2 3 7 6; %Cara 3
         3 4 8 7; %Cara 4
         5 6 7 8; %Cara 5
         1 2 3 4];%Cara 6


%Atributos básicos
vertice2 = 0.5;
ancho2 = 0.5;
largo2 = (dy+0.5)*2;
posX2 = dis/2;
%VERTICES Y CARAS DE LÁMINA (-)
                     % x               y              z
vertices2 = [-vertice2*ancho2+posX2  -vertice2*largo2  -vertice2;%Vertice 1
            -vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 2
             vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 3
             vertice2*ancho2+posX2  -vertice2*largo2  -vertice2; %Vertice 4
            -vertice2*ancho2+posX2  -vertice2*largo2   vertice2; %Vertice 5
            -vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 6
             vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 7
             vertice2*ancho2+posX2  -vertice2*largo2   vertice2]; %Vertice 8



k=8.998e9;
q= 1.6e-19;
q2= -1.6e-19;

%P1
nx = dx2;
ny = 0;
nz = 0;
Ex = k*q.*(xx+nx)./((xx+nx).^2+(yy+ny).^2).^1.5;  
Ey = k*q.*(yy+ny)./((xx+nx).^2+(yy+ny).^2).^1.5;
Ez = k*q.*(zz+nz)./((xx+nx).^2+(yy+ny).^2).^1.5;

%P2
nx3 = dx2;
ny3 = -dx;
nz3 = 0;
Ex3 = k*q.*(xx+nx3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;  
Ey3 = k*q.*(yy+ny3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;
Ez3 = k*q.*(zz+nz3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;

%P3
nx5 = dx2;
ny5 = dx;
nz5 = 0;
Ex5 = k*q.*(xx+nx5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;  
Ey5 = k*q.*(yy+ny5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;
Ez5 = k*q.*(zz+nz5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;


%Partículas negativas

%P1
nx2 = -dy2;
ny2 = dy;
nz2 = 0;
Ex2 = k*q2.*(xx+nx2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;  
Ey2 = k*q2.*(yy+ny2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;
Ez2 = k*q2.*(zz+nz2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;

%P2

nx4 = -dy2;
ny4 = 0;
nz4 = 0;
Ex4 = k*q2.*(xx+nx4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;  
Ey4 = k*q2.*(yy+ny4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;
Ez4 = k*q2.*(zz+nz4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;

%P3
nx6 = -dy2;
ny6 = -dy;
nz6 = 0;
Ex6 = k*q2.*(xx+nx6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;  
Ey6 = k*q2.*(yy+ny6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;
Ez6= k*q2.*(zz+nz6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;


x2 = size(xx);
y2 = size(yy);
z2 = size(zz);

for x = 1:x2
    for y = 1:y2
        for z = 1:z2
            
            %Magnitud del vector total
             Vec = sqrt((Ex.^2+Ex2.^2+Ex3.^2+Ex4.^2+Ex5.^2+Ex6.^2)+(Ey.^2+Ey2.^2+Ey3.^2+Ey4.^2+Ey5.^2+Ey6.^2));
             
             %Componentes en u, j y k
             Ex = Ex./Vec;
             Ey = Ey./Vec;
             Ez = Ez./Vec;

             Ex2 = Ex2./Vec;
             Ey2 = Ey2./Vec;
             Ez2 = Ez2./Vec;
             
             Ex3 = Ex3./Vec;
             Ey3 = Ey3./Vec;
             Ez3 = Ez3./Vec;
             
             Ex4 = Ex4./Vec;
             Ey4 = Ey4./Vec;
             Ez4 = Ez4./Vec;
             
             Ex5 = Ex5./Vec;
             Ey5 = Ey5./Vec;
             Ez5 = Ez5./Vec;
             
             Ex6 = Ex6./Vec;
             Ey6 = Ey6./Vec;
             Ez6 = Ez6./Vec;
             

            
             %Llenado de la matriz vectorial
             cx(x,y) = (Ex(x,y))+(Ex2(x,y))+(Ex3(x,y)+(Ex4(x,y))+(Ex5(x,y))+(Ex6(x,y)));
             cy(x,y)=Ey(x,y)+Ey2(x,y)+Ey3(x,y)+Ey4(x,y)+Ey5(x,y)+Ey6(x,y);
             cz(x,y)=Ez(x,y)+ Ez2(x,y)+Ez3(x,y)+Ez4(x,y)+Ez5(x,y)+(Ez6(x,y));
                 
        end
    end
end


quiver3(xx,yy,zz,cx,cy, cz);
patch('Faces',caras,'Vertices',vertices,'FaceColor','r');
patch('Faces',caras,'Vertices',vertices2,'FaceColor','b');
axis([-3 3 -3 3 -3 3]);
view(30,30); 
grid();
text(dx2,0,0.8,'-','Color','white','FontSize',30);
text(-dx2,0,0.8,'+','Color','white','FontSize',20);
xlabel('x')
ylabel('y')
zlabel('z')
hold off


% Hints: get(hObject,'Value') returns position of slider
%        get(hObject,'Min') and get(hObject,'Max') to determine range of slider


% --- Executes during object creation, after setting all properties.
function distancia_CreateFcn(hObject, eventdata, handles)
% hObject    handle to distancia (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called

if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes on slider movement.
function longitud_Callback(hObject, eventdata, handles)
% hObject    handle to longitud (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
rotate3d 
cla;

m=5;
dm=0.3;
[xx, yy]=meshgrid(-m:dm:m);
zz = xx.*0;

dis = get(handles.distancia,'Value');
dy = get(handles.longitud, 'Value');
dx = get(handles.longitudx, 'Value');
dy2 = dis/2;

dx2 = dis/2;

%Atributos básicos
vertice = 0.5;
ancho = 0.5;
largo = (dx+0.5)*2;
posX = dis/2;

%Vertices y caras de la placa positiva
                        % x               y          z
vertices = [-vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 1
            -vertice*ancho-posX   vertice*largo  -vertice; %Vertice 2
             vertice*ancho-posX   vertice*largo  -vertice; %Vertice 3
             vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 4
            -vertice*ancho-posX  -vertice*largo   vertice; %Vertice 5
            -vertice*ancho-posX   vertice*largo   vertice; %Vertice 6
             vertice*ancho-posX   vertice*largo   vertice; %Vertice 7
             vertice*ancho-posX  -vertice*largo   vertice];%Vertice 8
         
caras = [1 5 8 4; %Cara 1
         1 5 6 2; %Cara 2
         2 3 7 6; %Cara 3
         3 4 8 7; %Cara 4
         5 6 7 8; %Cara 5
         1 2 3 4];%Cara 6


%Atributos básicos
vertice2 = 0.5;
ancho2 = 0.5;
largo2 = (dy+0.5)*2;
posX2 = dis/2;
%VERTICES Y CARAS DE LÁMINA (-)
                     % x               y              z
vertices2 = [-vertice2*ancho2+posX2  -vertice2*largo2  -vertice2;%Vertice 1
            -vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 2
             vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 3
             vertice2*ancho2+posX2  -vertice2*largo2  -vertice2; %Vertice 4
            -vertice2*ancho2+posX2  -vertice2*largo2   vertice2; %Vertice 5
            -vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 6
             vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 7
             vertice2*ancho2+posX2  -vertice2*largo2   vertice2]; %Vertice 8



k=8.998e9;
q= 1.6e-19;
q2= -1.6e-19;

%P1
nx = dx2;
ny = 0;
nz = 0;
Ex = k*q.*(xx+nx)./((xx+nx).^2+(yy+ny).^2).^1.5;  
Ey = k*q.*(yy+ny)./((xx+nx).^2+(yy+ny).^2).^1.5;
Ez = k*q.*(zz+nz)./((xx+nx).^2+(yy+ny).^2).^1.5;

%P2
nx3 = dx2;
ny3 = -dx;
nz3 = 0;
Ex3 = k*q.*(xx+nx3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;  
Ey3 = k*q.*(yy+ny3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;
Ez3 = k*q.*(zz+nz3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;

%P3
nx5 = dx2;
ny5 = dx;
nz5 = 0;
Ex5 = k*q.*(xx+nx5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;  
Ey5 = k*q.*(yy+ny5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;
Ez5 = k*q.*(zz+nz5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;


%Partículas negativas

%P1
nx2 = -dy2;
ny2 = dy;
nz2 = 0;
Ex2 = k*q2.*(xx+nx2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;  
Ey2 = k*q2.*(yy+ny2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;
Ez2 = k*q2.*(zz+nz2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;

%P2

nx4 = -dy2;
ny4 = 0;
nz4 = 0;
Ex4 = k*q2.*(xx+nx4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;  
Ey4 = k*q2.*(yy+ny4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;
Ez4 = k*q2.*(zz+nz4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;

%P3
nx6 = -dy2;
ny6 = -dy;
nz6 = 0;
Ex6 = k*q2.*(xx+nx6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;  
Ey6 = k*q2.*(yy+ny6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;
Ez6= k*q2.*(zz+nz6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;


x2 = size(xx);
y2 = size(yy);
z2 = size(zz);

for x = 1:x2
    for y = 1:y2
        for z = 1:z2
            
            %Magnitud del vector total
             Vec = sqrt((Ex.^2+Ex2.^2+Ex3.^2+Ex4.^2+Ex5.^2+Ex6.^2)+(Ey.^2+Ey2.^2+Ey3.^2+Ey4.^2+Ey5.^2+Ey6.^2));
             
             %Componentes en u, j y k
             Ex = Ex./Vec;
             Ey = Ey./Vec;
             Ez = Ez./Vec;

             Ex2 = Ex2./Vec;
             Ey2 = Ey2./Vec;
             Ez2 = Ez2./Vec;
             
             Ex3 = Ex3./Vec;
             Ey3 = Ey3./Vec;
             Ez3 = Ez3./Vec;
             
             Ex4 = Ex4./Vec;
             Ey4 = Ey4./Vec;
             Ez4 = Ez4./Vec;
             
             Ex5 = Ex5./Vec;
             Ey5 = Ey5./Vec;
             Ez5 = Ez5./Vec;
             
             Ex6 = Ex6./Vec;
             Ey6 = Ey6./Vec;
             Ez6 = Ez6./Vec;
             

            
             %Llenado de la matriz vectorial
             cx(x,y) = (Ex(x,y))+(Ex2(x,y))+(Ex3(x,y)+(Ex4(x,y))+(Ex5(x,y))+(Ex6(x,y)));
             cy(x,y)=Ey(x,y)+Ey2(x,y)+Ey3(x,y)+Ey4(x,y)+Ey5(x,y)+Ey6(x,y);
             cz(x,y)=Ez(x,y)+ Ez2(x,y)+Ez3(x,y)+Ez4(x,y)+Ez5(x,y)+(Ez6(x,y));
                 
        end
    end
end


quiver3(xx,yy,zz,cx,cy, cz);
patch('Faces',caras,'Vertices',vertices,'FaceColor','r');
patch('Faces',caras,'Vertices',vertices2,'FaceColor','b');
axis([-3 3 -3 3 -3 3]);
view(30,30); 
grid();
text(dx2,0,0.8,'-','Color','white','FontSize',30);
text(-dx2,0,0.8,'+','Color','white','FontSize',20);
xlabel('x')
ylabel('y')
zlabel('z')
hold off




% --- Executes during object creation, after setting all properties.
function longitud_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end


% --- Executes during object creation, after setting all properties.
function axes1_CreateFcn(hObject, eventdata, handles)
% hObject    handle to axes1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    empty - handles not created until after all CreateFcns called


% Hint: place code in OpeningFcn to populate axes1



function edit1_Callback(hObject, eventdata, handles)
% hObject    handle to edit1 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)


% --- Executes during object creation, after setting all properties.
function edit1_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end



function edit3_Callback(hObject, eventdata, handles)
% hObject    handle to edit3 (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)



% --- Executes during object creation, after setting all properties.
function edit3_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


%Coordenada en x
function coordx_Callback(hObject, eventdata, handles)
clc;
xg = get(handles.coordx, 'String');
handles.xg = xg;
xg = str2double(xg);
disp("Valor en x");
disp(xg)
yg = get(handles.coordy, 'String');
handles.yg = yg;
yg = str2double(yg);
disp("Valor en y");
disp(yg)
zg = get(handles.coordz, 'String');
handles.zg = zg;
zg = str2double(zg);
disp("Valor en z");
disp(zg)





% Hints: get(hObject,'String') returns contents of coordx as text
%        str2double(get(hObject,'String')) returns contents of coordx as a double


% --- Executes during object creation, after setting all properties.
function coordx_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end

%Coordenada en y
function coordy_Callback(hObject, eventdata, handles)
clc;
xg = get(handles.coordx, 'String');
handles.xg = xg;
xg = str2double(xg);
disp("Valor en x");
disp(xg)
yg = get(handles.coordy, 'String');
handles.yg = yg;
yg = str2double(yg);
disp("Valor en y");
disp(yg)
zg = get(handles.coordz, 'String');
handles.zg = zg;
zg = str2double(zg);
disp("Valor en z");
disp(zg)



% Hints: get(hObject,'String') returns contents of coordy as text
%        str2double(get(hObject,'String')) returns contents of coordy as a double


% --- Executes during object creation, after setting all properties.
function coordy_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


%Coordenada en z
function coordz_Callback(hObject, eventdata, handles)
% hObject    handle to coordz (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)
clc;
xg = get(handles.coordx, 'String');
handles.xg = xg;
xg = str2double(xg);
disp("Valor en x");
disp(xg)
yg = get(handles.coordy, 'String');
handles.yg = yg;
yg = str2double(yg);
disp("Valor en y");
disp(yg)
zg = get(handles.coordz, 'String');
handles.zg = zg;
zg = str2double(zg);
disp("Valor en z");
disp(zg)




% Hints: get(hObject,'String') returns contents of coordz as text
%        str2double(get(hObject,'String')) returns contents of coordz as a double


% --- Executes during object creation, after setting all properties.
function coordz_CreateFcn(hObject, eventdata, handles)
if ispc && isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor','white');
end


% --- Executes on button press in pushbutton1.
function pushbutton1_Callback(hObject, eventdata, handles)


rotate3d 
cla;

m=5;
dm=0.3;
[xx, yy]=meshgrid(-m:dm:m);
zz = xx.*0;

dis = get(handles.distancia,'Value');
dy = get(handles.longitud, 'Value');
dx = get(handles.longitudx, 'Value');
dy2 = dis/2;
dx2 = dis/2;

%Atributos básicos
vertice = 0.5;
ancho = 0.5;
largo = (dx+0.5)*2;
posX = dis/2;

%Vertices y caras de la placa positiva
                        % x               y          z
vertices = [-vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 1
            -vertice*ancho-posX   vertice*largo  -vertice; %Vertice 2
             vertice*ancho-posX   vertice*largo  -vertice; %Vertice 3
             vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 4
            -vertice*ancho-posX  -vertice*largo   vertice; %Vertice 5
            -vertice*ancho-posX   vertice*largo   vertice; %Vertice 6
             vertice*ancho-posX   vertice*largo   vertice; %Vertice 7
             vertice*ancho-posX  -vertice*largo   vertice];%Vertice 8
         
caras = [1 5 8 4; %Cara 1
         1 5 6 2; %Cara 2
         2 3 7 6; %Cara 3
         3 4 8 7; %Cara 4
         5 6 7 8; %Cara 5
         1 2 3 4];%Cara 6


%Atributos básicos
vertice2 = 0.5;
ancho2 = 0.5;
largo2 = (dy+0.5)*2;
posX2 = dis/2;
%VERTICES Y CARAS DE LÁMINA (-)
                     % x               y              z
vertices2 = [-vertice2*ancho2+posX2  -vertice2*largo2  -vertice2;%Vertice 1
            -vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 2
             vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 3
             vertice2*ancho2+posX2  -vertice2*largo2  -vertice2; %Vertice 4
            -vertice2*ancho2+posX2  -vertice2*largo2   vertice2; %Vertice 5
            -vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 6
             vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 7
             vertice2*ancho2+posX2  -vertice2*largo2   vertice2]; %Vertice 8



k=8.998e9;
q= 1.6e-19;
q2= -1.6e-19;

%P1
nx = dx2;
ny = 0;
nz = 0;
Ex = k*q.*(xx+nx)./((xx+nx).^2+(yy+ny).^2).^1.5;  
Ey = k*q.*(yy+ny)./((xx+nx).^2+(yy+ny).^2).^1.5;
Ez = k*q.*(zz+nz)./((xx+nx).^2+(yy+ny).^2).^1.5;

%P2
nx3 = dx2;
ny3 = -dx;
nz3 = 0;
Ex3 = k*q.*(xx+nx3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;  
Ey3 = k*q.*(yy+ny3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;
Ez3 = k*q.*(zz+nz3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;

%P3
nx5 = dx2;
ny5 = dx;
nz5 = 0;
Ex5 = k*q.*(xx+nx5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;  
Ey5 = k*q.*(yy+ny5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;
Ez5 = k*q.*(zz+nz5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;


%Partículas negativas

%P1
nx2 = -dy2;
ny2 = dy;
nz2 = 0;
Ex2 = k*q2.*(xx+nx2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;  
Ey2 = k*q2.*(yy+ny2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;
Ez2 = k*q2.*(zz+nz2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;

%P2

nx4 = -dy2;
ny4 = 0;
nz4 = 0;
Ex4 = k*q2.*(xx+nx4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;  
Ey4 = k*q2.*(yy+ny4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;
Ez4 = k*q2.*(zz+nz4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;

%P3
nx6 = -dy2;
ny6 = -dy;
nz6 = 0;
Ex6 = k*q2.*(xx+nx6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;  
Ey6 = k*q2.*(yy+ny6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;
Ez6= k*q2.*(zz+nz6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;


x2 = size(xx);
y2 = size(yy);
z2 = size(zz);

for x = 1:x2
    for y = 1:y2
        for z = 1:z2
            
            %Magnitud del vector total
             Vec = sqrt((Ex.^2+Ex2.^2+Ex3.^2+Ex4.^2+Ex5.^2+Ex6.^2)+(Ey.^2+Ey2.^2+Ey3.^2+Ey4.^2+Ey5.^2+Ey6.^2));
             
             %Componentes en u, j y k
             Ex = Ex./Vec;
             Ey = Ey./Vec;
             Ez = Ez./Vec;

             Ex2 = Ex2./Vec;
             Ey2 = Ey2./Vec;
             Ez2 = Ez2./Vec;
             
             Ex3 = Ex3./Vec;
             Ey3 = Ey3./Vec;
             Ez3 = Ez3./Vec;
             
             Ex4 = Ex4./Vec;
             Ey4 = Ey4./Vec;
             Ez4 = Ez4./Vec;
             
             Ex5 = Ex5./Vec;
             Ey5 = Ey5./Vec;
             Ez5 = Ez5./Vec;
             
             Ex6 = Ex6./Vec;
             Ey6 = Ey6./Vec;
             Ez6 = Ez6./Vec;
             

            
             %Llenado de la matriz vectorial
             cx(x,y) = (Ex(x,y))+(Ex2(x,y))+(Ex3(x,y)+(Ex4(x,y))+(Ex5(x,y))+(Ex6(x,y)));
             cy(x,y)=Ey(x,y)+Ey2(x,y)+Ey3(x,y)+Ey4(x,y)+Ey5(x,y)+Ey6(x,y);
             cz(x,y)=Ez(x,y)+ Ez2(x,y)+Ez3(x,y)+Ez4(x,y)+Ez5(x,y)+(Ez6(x,y));
                 
        end
    end
end


%Creación y cálculo del campo eléctrico del glóbulo
clc;
xg = get(handles.coordx, 'String');
handles.xg = xg;
xg = str2double(xg);
disp("Valor en x");
disp(xg)
yg = get(handles.coordy, 'String');
handles.yg = yg;
yg = str2double(yg);
disp("Valor en y");
disp(yg)
zg = get(handles.coordz, 'String');
handles.zg = zg;
zg = str2double(zg);
disp("Valor en z");
disp(zg)

%Atributos de las placas
dis = get(handles.distancia,'Value');
dy = get(handles.longitud, 'Value');
dy2 = dis/2;
dx = 1;
dx2 = dis/2;


k=8.998e9;

%Coordenadas de las particulas positivas

%P1
nx = dx2;
ny = 0;
nz = 0;

%P2
nx3 = dx2;
ny3 = -dx;
nz3 = 0;

%P3
nx5 = dx2;
ny5 = dx;
nz5 = 0;


%Coordenadas de las partículas negativas

%P1
nx2 = -dy2;
ny2 = dy;
nz2 = 0;

%P2
nx4 = -dy2;
ny4 = 0;
nz4 = 0;
%P3
nx6 = -dy2;
ny6 = -dy;
nz6 = 0;


%Cargas de ambos lados del glóbulo
%Creados aleatoriamente entre 1e-19 a 1.1e-19

r = 1e-19 + (1.1e-19+0)*rand(1,1);
q = -r;
r2 = 1e-19 + (1.1e-19+0)*rand(1,1);
q2 = (r2);

%Diametro aproximado de un glóbulo
d = 0.737;
xgd = xg + d;


%Clausula para que las coordenadas esten dentro del rango de las placas
lim_y = dy*2;
if yg > lim_y || yg<-lim_y || xg > dy2 || xg<-dy2
    disp("Coordenadas fuera de rango")
    disp("Por favor regingrese los datos")
end

%Cálculo del campo eléctrico izquierdo

%P1
xg1 = xg - nx;
yg1 = yg - ny;
zg1 = zg - nz;
rg1 = sqrt(abs(xg1^2+yg1^2+zg1^2));    
Exg1 = (k*q*xg1)/rg1^3;
Eyg1 = (k*q*yg1)/rg1^3;
Ezg1 = (k*q*zg1)/rg1^3;

%P2
xg2 = xg - nx3;
yg2 = yg - ny3;
zg2 = zg-nz3;
rg2 = sqrt(xg2^2+yg2^2+zg2^2);

Exg2 = (k*q*xg2)/rg2^3;
Eyg2 = (k*q*yg2)/rg2^3;
Ezg2 = (k*q*zg2)/rg2^3;

%P3
xg3 = xg - nx5;
yg3 = yg - ny5;
zg3 = zg-nz5;
rg3 = sqrt(xg3^2+yg3^2+zg3^2);

Exg3 = (k*q*xg3)/rg3^3;
Eyg3 = (k*q*yg3)/rg3^3;
Ezg3 = (k*q*zg3)/rg3^3;

%Campo total izquierdo en x, y, z
Exg = Exg1 + Exg2 + Exg3;
Eyg = Eyg1 + Eyg2 + Eyg3;
Ezg = Ezg1 + Ezg2 + Ezg3;


%Cálculo del campo eléctrico derecho

%P1
xg4 = xgd - nx2;
yg4 = yg - ny2;
zg4 = zg-nz2;
rg4 = sqrt(xg4^2+yg4^2+zg4^2);

Exg4 = (k*q2*xg4)/rg4^3;
Eyg4 = (k*q2*yg4)/rg4^3;
Ezg4 = (k*q2*zg4)/rg4^3;

%P2
xg5 = xgd - nx4;
yg5 = yg - ny4;
zg5 = zg-nz4;
rg5 = sqrt(xg5^2+yg5^2+zg5^2);

Exg5 = (k*q2*xg5)/rg5^3;
Eyg5 = (k*q2*yg5)/rg5^3;
Ezg5 = (k*q2*zg5)/rg5^3;

%P3
xg6 = xgd - nx6;
yg6 = yg - ny6;
zg6 = zg-nz6;
rg6 = sqrt(xg5^2+yg5^2+zg5^2);

Exg6 = (k*q2*xg6)/rg6^3;
Eyg6 = (k*q2*yg6)/rg6^3;
Ezg6 = (k*q2*zg6)/rg6^3;

%Campo eléctrico derecho total en x, y, z
Exgd = Exg4 + Exg5 + Exg6;
Eygd = Eyg4 + Eyg5 + Eyg6;
Ezgd = Ezg4 + Ezg5 + Ezg6;

%Campos eléctricos totales
Eizq = sqrt(Exg^2+Eyg^2+Ezg^2);
Eder = sqrt(abs(Exgd^2 + Eygd^2 + Ezgd^2));

%Muestreo de los datos, campos eléctricos y diferencia entre ellos
if yg > lim_y || yg<-lim_y || xg > dy2 || xg<-dy2
    disp("")
     set(handles.text18, 'string', "Coordenadas fuera de rango");
else
    error = abs(((Eizq - Eder)/Eizq)*100);
    ea = abs(error);
    set(handles.text12,'string',Eizq)
    set(handles.text13,'string',Eder)
    set(handles.text16, 'string', ea)
    if error > 10
        set(handles.text18, 'string', "Glóbulo infectado");
    else
        set(handles.text18, 'string', "Glóbulo sano");
    end
    

%Graficación del campo entre las placas
quiver3(xx,yy,zz,cx,cy,cz,'autoscalefactor',1);
hold on
%Graficación de los puntos dónde se encuentra el glóbulo
plot3(xg, yg, zg, 'b o', 'Markersize', 5);
plot3(xg, yg, zg, 'b +', 'Markersize', 5);

plot3(xgd, yg, zg, 'b o', 'Markersize', 5);
plot3(xgd, yg, zg, 'b +', 'Markersize', 5);

patch('Faces',caras,'Vertices',vertices,'FaceColor','r');
patch('Faces',caras,'Vertices',vertices2,'FaceColor','b');
axis([-3 3 -3 3 -3 3]);
view(30,30); 
grid();
text(dx2,0,0.8,'-','Color','white','FontSize',30);
text(-dx2,0,0.8,'+','Color','white','FontSize',20);
xlabel('x')
ylabel('y')
zlabel('z')
hold off
end


% --- Executes on slider movement.
function longitudx_Callback(hObject, eventdata, handles)
% hObject    handle to longitudx (see GCBO)
% eventdata  reserved - to be defined in a future version of MATLAB
% handles    structure with handles and user data (see GUIDATA)

rotate3d 
cla;

m=5;
dm=0.3;
[xx, yy]=meshgrid(-m:dm:m);
zz = xx.*0;

dis = get(handles.distancia,'Value');
dy = get(handles.longitud, 'Value');
dx = get(handles.longitudx, 'Value');
dy2 = dis/2;

dx2 = dis/2;

%Atributos básicos
vertice = 0.5;
ancho = 0.5;
largo = (dx+0.5)*2;
posX = dis/2;

%Vertices y caras de la placa positiva
                        % x               y          z
vertices = [-vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 1
            -vertice*ancho-posX   vertice*largo  -vertice; %Vertice 2
             vertice*ancho-posX   vertice*largo  -vertice; %Vertice 3
             vertice*ancho-posX  -vertice*largo  -vertice; %Vertice 4
            -vertice*ancho-posX  -vertice*largo   vertice; %Vertice 5
            -vertice*ancho-posX   vertice*largo   vertice; %Vertice 6
             vertice*ancho-posX   vertice*largo   vertice; %Vertice 7
             vertice*ancho-posX  -vertice*largo   vertice];%Vertice 8
         
caras = [1 5 8 4; %Cara 1
         1 5 6 2; %Cara 2
         2 3 7 6; %Cara 3
         3 4 8 7; %Cara 4
         5 6 7 8; %Cara 5
         1 2 3 4];%Cara 6


%Atributos básicos
vertice2 = 0.5;
ancho2 = 0.5;
largo2 = (dy+0.5)*2;
posX2 = dis/2;
%VERTICES Y CARAS DE LÁMINA (-)
                     % x               y              z
vertices2 = [-vertice2*ancho2+posX2  -vertice2*largo2  -vertice2;%Vertice 1
            -vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 2
             vertice2*ancho2+posX2   vertice2*largo2  -vertice2; %Vertice 3
             vertice2*ancho2+posX2  -vertice2*largo2  -vertice2; %Vertice 4
            -vertice2*ancho2+posX2  -vertice2*largo2   vertice2; %Vertice 5
            -vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 6
             vertice2*ancho2+posX2   vertice2*largo2   vertice2; %Vertice 7
             vertice2*ancho2+posX2  -vertice2*largo2   vertice2]; %Vertice 8



k=8.998e9;
q= 1.6e-19;
q2= -1.6e-19;

%P1
nx = dx2;
ny = 0;
nz = 0;
Ex = k*q.*(xx+nx)./((xx+nx).^2+(yy+ny).^2).^1.5;  
Ey = k*q.*(yy+ny)./((xx+nx).^2+(yy+ny).^2).^1.5;
Ez = k*q.*(zz+nz)./((xx+nx).^2+(yy+ny).^2).^1.5;

%P2
nx3 = dx2;
ny3 = -dx;
nz3 = 0;
Ex3 = k*q.*(xx+nx3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;  
Ey3 = k*q.*(yy+ny3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;
Ez3 = k*q.*(zz+nz3)./((xx+nx3).^2+(yy+ny3).^2).^1.5;

%P3
nx5 = dx2;
ny5 = dx;
nz5 = 0;
Ex5 = k*q.*(xx+nx5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;  
Ey5 = k*q.*(yy+ny5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;
Ez5 = k*q.*(zz+nz5)./((xx+nx5).^2+(yy+ny5).^2).^1.5;


%Partículas negativas

%P1
nx2 = -dy2;
ny2 = dy;
nz2 = 0;
Ex2 = k*q2.*(xx+nx2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;  
Ey2 = k*q2.*(yy+ny2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;
Ez2 = k*q2.*(zz+nz2)./((xx+nx2).^2+(yy+ny2).^2).^1.5;

%P2

nx4 = -dy2;
ny4 = 0;
nz4 = 0;
Ex4 = k*q2.*(xx+nx4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;  
Ey4 = k*q2.*(yy+ny4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;
Ez4 = k*q2.*(zz+nz4)./((xx+nx4).^2+(yy+ny4).^2).^1.5;

%P3
nx6 = -dy2;
ny6 = -dy;
nz6 = 0;
Ex6 = k*q2.*(xx+nx6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;  
Ey6 = k*q2.*(yy+ny6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;
Ez6= k*q2.*(zz+nz6)./((xx+nx6).^2+(yy+ny6).^2).^1.5;


x2 = size(xx);
y2 = size(yy);
z2 = size(zz);

for x = 1:x2
    for y = 1:y2
        for z = 1:z2
            
            %Magnitud del vector total
             Vec = sqrt((Ex.^2+Ex2.^2+Ex3.^2+Ex4.^2+Ex5.^2+Ex6.^2)+(Ey.^2+Ey2.^2+Ey3.^2+Ey4.^2+Ey5.^2+Ey6.^2));
             
             %Componentes en u, j y k
             Ex = Ex./Vec;
             Ey = Ey./Vec;
             Ez = Ez./Vec;

             Ex2 = Ex2./Vec;
             Ey2 = Ey2./Vec;
             Ez2 = Ez2./Vec;
             
             Ex3 = Ex3./Vec;
             Ey3 = Ey3./Vec;
             Ez3 = Ez3./Vec;
             
             Ex4 = Ex4./Vec;
             Ey4 = Ey4./Vec;
             Ez4 = Ez4./Vec;
             
             Ex5 = Ex5./Vec;
             Ey5 = Ey5./Vec;
             Ez5 = Ez5./Vec;
             
             Ex6 = Ex6./Vec;
             Ey6 = Ey6./Vec;
             Ez6 = Ez6./Vec;
             

            
             %Llenado de la matriz vectorial
             cx(x,y) = (Ex(x,y))+(Ex2(x,y))+(Ex3(x,y)+(Ex4(x,y))+(Ex5(x,y))+(Ex6(x,y)));
             cy(x,y)=Ey(x,y)+Ey2(x,y)+Ey3(x,y)+Ey4(x,y)+Ey5(x,y)+Ey6(x,y);
             cz(x,y)=Ez(x,y)+ Ez2(x,y)+Ez3(x,y)+Ez4(x,y)+Ez5(x,y)+(Ez6(x,y));
                 
        end
    end
end

rotate3d 
quiver3(xx,yy,zz,cx,cy, cz);
patch('Faces',caras,'Vertices',vertices,'FaceColor','r');
patch('Faces',caras,'Vertices',vertices2,'FaceColor','b');
axis([-3 3 -3 3 -3 3]);
view(30,30); 
grid();
text(dx2,0,0.8,'-','Color','white','FontSize',30);
text(-dx2,0,0.8,'+','Color','white','FontSize',20);
xlabel('x')
ylabel('y')
zlabel('z')
hold off




% --- Executes during object creation, after setting all properties.
function longitudx_CreateFcn(hObject, eventdata, handles)
if isequal(get(hObject,'BackgroundColor'), get(0,'defaultUicontrolBackgroundColor'))
    set(hObject,'BackgroundColor',[.9 .9 .9]);
end
