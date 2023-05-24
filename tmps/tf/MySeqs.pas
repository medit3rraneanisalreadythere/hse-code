unit MySeqs;

function SeqOfYear (b,e:integer): sequence of integer;
begin
  Assert(e >= b);
  for var i := b to e do
  begin
    yield i;
  end;
end;


function GenOddInfinity(start:integer): sequence of integer;
begin
  while True do
  begin
    yield start;
    start += 1;
  end;
end;


function GenRandomInfinity(a,b:integer): sequence of integer;
begin
  While True do
  begin
    yield Random(a,b);
  end;
end;


function SumMinusSeq(s : sequence of integer; a1,a2: integer) :  integer;
begin
  Result := s.Skip(a1).Take(a2-a1).Where(x->x<0).Sum;
end;

function EltD(s: sequence of integer; d: integer): integer;
begin
  Result := s.FirstOrDefault(x -> (abs(x) mod 10 = d) and (x > 0));
end;


function MinPl(s : sequence of integer): (integer, integer);
begin
  Result := (S.FirstOrDefault(x -> x > 0),  S.Last(x -> x < 0));
end;

function ACount(A : sequence of string; C : string): integer;
begin
  Result := A.Count(x -> (x.Length > 1) and (x[1] = C) and (x[(x.Length)] = C));
end;

function MinMinus(s : sequence of integer): integer;
begin
  Result := S.Where(x -> x < 0).DefaultIfEmpty(42).Min;
end;

function OddEven(s : sequence of integer) : (sequence of integer, sequence of integer);
begin
  Result := (s.Where(x -> x mod 2 = 0), s.Where(x-> x mod 2 <> 0));
end;

function LastDigits(s : sequence of integer) : sequence of integer;
begin
  Result := S.Where(x -> x > 0).Select(x-> x mod 10).Distinct;
end;


begin
end.