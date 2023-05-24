uses GraphABC, ABCObjects, System.Timers;

const brickCount = 19;
const brickWidth = 50; // ширина кирпича
const brickHeight = 20; // высота кирпича 
const gapBetweenBricks = 2; // расстояние между кирпичами
const sliderGap = 100; // отступ снизу для ракетки
const sliderWidth = 100; // ширина ракетки
const sliderHeight = 20; // высота ракетки
const topGap = 100; //отступ сверху
const ballSize = 15; //размер мячика


var wallColors := Arr(
  Color.Red, Color.Orange, Color.Yellow, Color.Green, Color.Cyan);

var Slider: RectangleABC := nil;
var Ball: CircleABC := nil;
var gameTimer := new Timer(10);
var dx , dy : integer; 
var x_ball , y_ball : integer;
var score := 0;
var brick_quantity: integer;

procedure DrawWall(xWall, yWall: integer);
begin
  brick_quantity := Window.Width div(xWall+ gapBetweenBricks) - 1; 
  
  var delta_len := WindowWidth - (brick_quantity * xWall + (brick_quantity - 1) * gapBetweenBricks);
  delta_len := delta_len div 2; //вычисляем отступы слева и справа от окна
  
  var num_color := 0; //храним номер цвета в массиве
  
  var (x, y) := (0, topGap); //координаты прямоугольников
  
  for var lines := 1 to 10 do
  begin
    for var columns:= 1 to brick_quantity do
    begin
      if columns = 1 then //первый слева прямоугольник
      begin
        x+= delta_len;
        y += gapBetweenBricks;
        new RectangleABC(x, y, xWall, yWall, wallColors[num_color]);
        x+= xWall;
      end
      
      else if columns = brick_quantity then //последний справа прямоугольник
      begin
        x+= gapBetweenBricks;
        new RectangleABC(x, y, xWall, yWall, wallColors[num_color]);
        y+= gapBetweenBricks + yWall;
        x:= 0;
      end
      
      else  //все остальные прямоугольники
      begin
        x+= gapBetweenBricks;
        new RectangleABC(x, y,  xWall, yWall, wallColors[num_color]);
        x+= xWall;
      end;


    end;
    if (lines mod 2) = 0 then num_color += 1; //меняем номер цвета в массиве
  end;
end;

procedure MoveSlider(x, y, mousebutton: integer);
begin

  system.Windows.Forms.Cursor.Hide; //прячем курсор
  
  y := WindowHeight - sliderWidth; // фиксируем y
  if x > WindowWidth - sliderWidth then x := WindowWidth - sliderWidth // делаем так, чтобы ракетка не выходила за правый край окна
  else if x < 0 then x := 0; //делаем так, чтобы ракетка не выходила за левый край экрана

  Slider.Left := x //перемещаем нашу ракетку на координату x


end;

procedure CreateSlider(xSlider, ySlider: integer);
begin
  Slider := new RectangleABC(WindowWidth div 2 - xSlider div 2, WindowHeight - sliderGap ,xSlider, ySlider, Color.Black); //создаём ракетку
  
  OnMouseMove += MoveSlider; //передаём процедуре MoveSlider каждое изменение координат курсора 
end;

function getCollidingObject(x, y: integer): boolean;
begin
  var object_to_del := ObjectUnderPoint(x,y);
  Result := False;
  if object_to_del <> nil then
  begin
     if object_to_del = Slider then
     begin
       dy := - dy;
       Result := True;
     end
     else
     begin
       object_to_del.Destroy;
       dy := - dy;
       score += 1;
       Result := True;
     end;
  end;
end;


procedure Tick(source: Object; e: ElapsedEventArgs);
begin

  if score = brick_quantity*10 then OnClose();
  
  y_ball += dy;
  x_ball += dx;
  
  if y_ball >= (WindowHeight - ballSize*2) then 
    begin
      Window.Close();
    end
    
  else if y_ball <= 0 then 
    begin
    dy := -dy;
    end;
    
  if x_ball = 0 then dx := -dx
  else if x_ball >= (WindowWidth - 2*ballSize) then dx := - dx;
  
  if x_ball < 0 then dx := abs(x_ball) + 1;

  Ball.MoveTo(x_ball, y_ball);

  var lu, ll, rl, ru : boolean;

  lu := getCollidingObject(x_ball - 1, y_ball + 1); //левый верхний
  if not lu then ll := getCollidingObject(x_ball - 1, y_ball + 2*ballsize + 1 ) //левый нижний
  else if not ll then rl := getCollidingObject(x_ball + 2 * ballsize + 1 , y_ball+ 2*ballsize +1) //правый нижний
  else if not rl then ru := getCollidingObject(x_ball + ballsize*2 +1, y_ball +1); //правый верхний

  var ml := getCollidingObject(x_ball - 1, y_ball + ballsize);
  var mr := getCollidingObject(x_ball + 2*ballsize + 1, y_ball + ballsize );
  
end;




procedure CreateBall(xBall, yBall: integer);
begin
  Ball := new CircleABC(xBall, yBall, ballSize, color.Black);
  
end;

procedure Init();
begin
    var Window_width := 1024; // здесь можно изменить ширину экрана
    var Window_height := 900; // здесь можно изменить высоту экрана
    
    SetWindowSize(Window_width, Window_height); //ставим заданное выше разрешение окна
    Window.IsFixedSize := true; //запрещаем изменять размер окна
    Window.CenterOnScreen; // располагаем наше окно по центру экрана
  

    DrawWall(brickWidth, brickHeight); //рисуем стены
    CreateSlider(sliderWidth, sliderHeight); //рисуем ракетку
    
    x_ball := WindowWidth div 2;
    y_ball := WindowHeight div 2;
    CreateBall(x_ball, y_ball); // рисуем мяч  
  
    dx := Random(3,6);
    dy := 7;
    
    gameTimer.Elapsed += Tick;
    gameTimer.Start;

end;

begin
  Init();
end.