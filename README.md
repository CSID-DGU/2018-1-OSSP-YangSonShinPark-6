# OSSP-YSSP

_Do-Dodge : 두더지를 이용한 닷지게임_

 
---

* 개발환경 : LINUX / ECLIPSE C++ / SDL Library

* 실행과정 주요 작업  
  

###실행환경  

```

<1. SDL2 Setting>
  
* SDL2 Library 다운 <https://www.libsdl.org/download-2.0.php>
  
* Eclipse에 Project Property 설정
  
* Libraries -l SDL2
  

<2. SDL_image Setting>
  
* SDL_image 다운 <https://www.libsdl.org/projects/SDL_image/>
  
* Eclipse에 Project Property 설정
  
* Libraries -l SDL2_image
  

<3. SDL_mixer Setting>
  
* SDL_mixer 다운 <https://www.libsdl.org/projects/SDL_mixer/>
  
* Eclipse에 Project Property 설정
  
* Libraries -l SDL2_mixer

```
  

###게임설명  

```

<1. 기본 게임>
  
* SDL로 만들어진 닷지 형태의 런 게임
  
* 방해요소들을 피하고, 아이템을 먹어가며 최대한 오래 살아남는 것이 목적
  
* 좌우 이동을 입력 받을 수 있으며 이를 바탕으로 게임을 진행
  

<2. 동작 방식>
  
* Graphics Manager를 통해 윈도우를 구성하고 기본적인 사운드와 이미지 설정 초기화
  
* GameManager를 통해 Scene들을 초기화하고 현재 상태에 해당하는 Scene 출력 및 업데이트
  
* Scene들이 해당 Scene에서 사용되는 오브젝트들을 초기화하고 출력, 업데이트
  
* 각 Object들이 움직이며 해당 게임을 구성하는 형태
  

<3. 게임 진행>
  
* 메뉴 - 게임 / 메뉴 - 옵션의 두가지 형태로 이동이 가능함
  
* 시간 값을 이용하여 랜덤하게 설정된 시간이 지나면 랜덤한 패턴이 발생하여 해당 오브젝트를 피하는 게임
  
* 시간에 따른 난이도 상승이 있으며, 난이도는 속도로서 나타나게 된다
  

<4. 치트 코드>
  
* 현재 본 게임의 경우 시연을 위하여 실제 패턴이 만들어지는 부분에 대한 곳을 주석처리 해두었음
  
    -> 게임 업데이트 부분의 함수 호출 주석 부분을 지우면 정상작동
  
* 숫자 1~6 : 각 숫자에 해당하는 패턴이 등장
  
* 숫자 0 : 게임 난이도 증가(속도 증가)
  
* 숫자 9 : 부스트 아이템 사용

```
