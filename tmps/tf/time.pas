uses GraphABC, ABCObjects;

var h,m,s : integer;

procedure Secs(sec : integer);
begin
  var x := WindowWidth div 2 + round(260 * cos(sec *  pi / 30));
  var y := WindowHeight div 2 + round(260 * sin(sec *  pi / 30));
  Pen.Width := 2;
  Pen.Color := clRed;
  Line(WindowWidth div 2, WindowHeight div 2, x, y);
end;

procedure Clock(mins, hours : integer);
begin
  Pen.Color := clBlack;
  lockdrawing;
  var x_min := WindowWidth div 2 + round(200 * cos(mins *  pi / 30)) ;
  var y_min := WindowHeight div 2 + round(200 * sin(mins *  pi / 30));
  Pen.Width:= 4;
  Line(WindowWidth div 2, WindowHeight div 2, x_min, y_min);
  
  var x_hour := WindowWidth div 2 + round(150 * cos(hours *  pi / 6)) ;
  var y_hour := WindowHeight div 2 + round(150 * sin(hours *  pi / 6));
  Pen.Width:= 6;
  Line(WindowWidth div 2, WindowHeight div 2, x_hour, y_hour);
  redraw;
  
end;

procedure getTime();
begin
  var currTime := System.DateTime.Now; 
  h := currTime.Hour;
  m := currTime.Minute;
  s := currTime.Second;
  if h > 12 then h := h mod 12;
end;

procedure PrintCypher();
begin
  Circle(WindowWidth div 2, WindowHeight div 2, 300);
  Font.Name := 'Arial';
  Font.Style := fsBold;
  Font.Color := Color.Black;
  Font.Size := 20;
  var angle := 180;
  for var i := 1 to 12 do
  begin
    angle -= 30;
    TextOut( WindowWidth div 2 + round(265 * sin(angle * pi / 180)) - 10, WindowHeight div 2 + round(265 * cos(angle * pi / 180)) - 15, i.ToString);  
  end;
end;

procedure Init();
begin
  var Window_width := 800; // здесь можно изменить ширину экрана
  var Window_height := 700; // здесь можно изменить высоту экрана
  SetWindowSize(Window_width, Window_height); //ставим заданное выше разрешение окна
  Window.IsFixedSize := true; //запрещаем изменять размер окна
  Window.CenterOnScreen; // располагаем наше окно по центру экрана
  //var h,m,s : integer;
  PrintCypher();
  while True do
  begin
    PrintCypher();
    getTime();
    Secs(s - 15); //вычитаем 15, чтобы оказалось в нужной четверти
    Clock(m - 15, h - 15);
  end;
end;

begin  
  Init();
end.
