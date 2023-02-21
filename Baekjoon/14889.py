import sys

def solve(n,s,count):
#팀배정완료 확인 수/ 현재 마지막으로 팀에 들어간 선수의 번호 -1/ 전체 인원수
  global team, res
  if n==count:
    start = 0
    link = 0
    for i in range(count):
      for j in range(count):
        if i in team and j in team:
          start += ls[i][j]
        elif i not in team and j not in team:
          link += ls[i][j]
    res.append(abs(start-link))
  else:
    for i in range(s, count):#배열 편의상 선수 번호 -1
      if i not in team:
        team.append(i)
        solve(n+2,i,count)
        print(team)
        team.remove(i)
        

  

people = int(sys.stdin.readline())
ls = []
for i in range(people):
  ls.append(list(map(int,sys.stdin.readline().split())))
team = []
res = []

solve(0,0,people)
print(res)
print(min(res))