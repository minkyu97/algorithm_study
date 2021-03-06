# 알고리즘 스터디
## 문제풀이 싸이트
프로그래머스    https://programmers.co.kr/<br/>
백준          https://www.acmicpc.net/<br/>
백준 난이도별   https://solved.ac/problems/tags<br/>

## 규칙
1. `master` 브랜치에 직접 push하지 말것
2. 자기 이름으로 된 브랜치(ex. minkyu)를 파서 push할 것
3. 문제의 풀이는 해당 문제의 출처, 문제이름, 작성자 이름으로 된 폴더를 만들어서 README.md 파일에 설명을 함께 수록할 것(선택) (ex. 종만북_Boggle_이민규)
4. 각 문제를 올릴 때마다 `master` 브랜치에 Pull Request 하고 comment/review 등을 통해 서로의 코드를 살펴보고 리뷰하기

## git 간략 사용 설명서
Git이란??
코드의 변경사항을 추적하고 관리를 용이하게 해주는 분산버전관리시스템입니다.
다들 과제에서 발표자료를 만들거나 할 때,

> 전공발표.pptx<br/>
> 전공발표 최종.pptx<br/>
> 전공발표 진짜 최종.pptx<br/>
> 전공발표 찐찐찐 최종.pptx

처럼, 동일한 파일을 업데이트함에 따라 기존 내용도 혹시 몰라 보관하고 싶을 때 이렇게 중구난방으로 이름을 지어본 적 있으시죠?? <br/>
이때 과거의 코드를 숨겨서 컴퓨터가 알아서 관리하고 우리가 필요할 때 불러낼 수도 있으며, 팀원끼리 동일한 파일을 수정할 때 해당 파일의 병합을 손쉽게 도와주는 도구가 바로 git이라고 생각하시면 됩니다.<br/>
보통 로컬에서 git으로 버전관리를 시작할 때는 `git init`이라는 명령어로 해당 폴더에서 버전관리를 시작하겠다고 컴퓨터에 알리는 명령어를 사용하는데, 지금은 이미 git으로 관리가 되고있는 원격 저장소를 로컬로 불러오기만 하면 돼요!<br/>
`git --version` 명령어를 터미널이나 cmd에 입력하면 현재 깔려있는 git의 버전을 알 수 있는데, 아무 것도 안 나오는 분들은 git을 까는 것부터 시작하면 됩니다. 맥을 쓰시는 분들은 기본으로 git이 깔려있을테니 넘어가고, 윈도우 쓰시는 분들은 https://git-scm.com/downloads 여기서 git을 받아주세요. 저는 그냥 터미널에서 글자로 치는 게 편한데, 터미널이 익숙하지 않으신 분들은 그냥 GUI 버전을 다운받으셔도 됩니다! 

### 원격 저장소 로컬로 가져오기
``` shell
$ cd "원격 저장소를 불러올 폴더명"
$ git clone https://github.com/minkyu97/algorithm_study.git
```

### 로컬에서 개인 branch 파기
``` shell
$ git switch -c 브랜치명
## 위 명령어가 안 먹힐 시 아래 명령어 사용
$ git checkout -b 브랜치명
```

### git add
처음 어떤 파일을 만들었을 때, 해당 파일은 git의 관리 하에 있지 않습니다. 따라서 앞으로 이 파일의 변경사항을 추적하라고 명령을 내려줘야 하는데, 이때 사용하는 게 `git add`입니다. 파일을 수정했을 때에도 동일한 명령어를 이용해 변경사항을 git에게 알려줘야 합니다.<br/>
(참고로 어떤 파일이 관리 하에 있고 어떤 파일이 관리 하에 없는지를 보려면 `git status` 명령어를 이용하면 됩니다!!)
``` shell
## 특정 파일의 생성이나 변경사항, 삭제를 git에게 알려줄 때
$ git add 파일명
## 추가되거나 수정된 모든 파일을 추적할 때
$ git add .
$ git add -A
```
보통 `git add .`이나 `git add -A`를 주로 사용하시고, 특정 파일만 변경사항을 추적하고 싶을 때만 첫번째 명령어를 사용하시면 됩니다. 두번째, 세번째 명령어도 엄밀히는 무슨 차이가 있었는데 깜빡했네요... 아마 둘 중 어느 걸 사용해도 별 지장은 없을 겁니다.

### git commit
앱스토어나 플레이스토어에서 앱을 다운 받을 때, 해당 앱의 버전이 1.0.7 등으로 표시되어있는 걸 보신 적 있으시죠? 해당 버전은 이전 버전과 비교해서 여러 차이를 가지고 있을 거예요. 그런 차이들을 모아서 아 이제 앱을 한 번 업데이트 시킬 때가 됐구나! 할 때 버전을 올리는 거죠.<br/>
`git commit`이 바로 그런 일을 수행하는 명령어라고 볼 수 있어요. `git add` 명령어로 여러 파일의 수정사항을 저장했고, 이제 이러한 파일들의 변경사항을 하나의 버전으로 확정함으로써 이 버전에서 어떤 걸 변경했고, 만들어졌는지를 확인할 수 있는 기록을 만듦과 동시에 혹시 이후 버전에서 문제가 생겨서 과거의 버전으로 돌아가고 싶을 때, 해당 버전으로 돌아갈 수 있는 이정표를 남겨놓는 작업이죠.<br/>
다만, 버전을 업데이트할 때는 이 버전에서 뭘 수정했는지 꼭 사람이 읽을 수 있는 기록으로 남겨줘야 돼요. 이걸 commit message 라고 부릅니다.
``` shell
## add 되어있는 모든 파일의 변경사항을 확정할 때
$ git commit
## 버전의 변경사항을 기록함과 동시에 변경사항을 확정할 때
$ git commit -m "커밋 메세지"
## 모든 파일의 변경사항 add와 commit을 동시에 하고싶을 때(새로 만든 파일은 포함이 안 돼요)
$ git commit -am "커밋 메세지"
```
참고로 첫번째 명령어를 사용하면 터미널 텍스트 편집기인 vi가 자동으로 켜지고, 거기서 버전의 변경사항을 기록한 뒤 저장해야 하는데, vi가 익숙하지 않은 분들은 2번째 명령어를 사용하세요. 개인적으로 vi 사용법이 어렵지 않으니 이 참에 알아둬도 좋을 것 같다고 생각합니다!..

### git push
지금까지 한 모든 작업들은 로컬의 git에만 기록되어있습니다. 이제 이 기록들을 원격저장소에 업로드하는 작업이 필요하죠. 이건 엄청 간단해요! 그냥 다음 명령어를 쓰시면 됩니다.
``` shell
$ git push origin 브랜치명
```
예를 들어 제 로컬 minkyu 브랜치에서 원격 minkyu 브랜치로 push하고 싶을 때는 `git push origin minkyu`를 쓰시면 됩니다.

### gitignore
`git add .` 등으로 여러 파일을 동시에 추가하고싶은데, 딱 하나의 파일만 제외하고 싶을때, 그리고 그 파일은 앞으로도 add할 일이 없을 때는 매번 그 파일만 제외하고 다른 파일들을 일일이 add하는 건 여간 번거로운 일이 아니겠죠? 그럴 땐 `.gitignore`라는 파일을 만들어 놓으면 거기에 기록되어있는 파일은 알아서 git이 무시하고 add를 하지 않으니, 안심하고 `git add .`을 사용하시면 됩니다.<br/>
터미널에서 만드려면 다음 명령어를 사용해서 `.gitignore`파일을 만든 뒤에, 줄바꿈으로 구분해가며 무시하고 싶은 파일명들을 기록해보세요.
``` shell
$ echo ".gitignore" >> .gitignore
```
윈도우에서는 좀 다를 수 있는데 제가 윈도우를 안 써서 정확히는 모르겠네요 ㅠㅠ 윈도우 쓰시는 분들은 한 번 구글링 해보세요!
