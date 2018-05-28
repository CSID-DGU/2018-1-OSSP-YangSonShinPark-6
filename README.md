# 라이브러리 세부 설명

_0. 라이브러리 구성_
* CGraphicsManager가 최상단으로 Window를 구성하고 사용할 Image 설정을 해준다.
> Update에서는 본격적으로 Game을 실행해 주며 Loop마다 윈도우 화면을 갱신해주어 항상 최신 상태의 화면을 출력한다.
* CGameManager는 전반적인 GameScene들을 관리해주는 역할이다.
> Scene들의 초기화와 상태에 맞는 Update/Render를 관리하며 해당 상태는 전역변수인 g_nState가 담당한다.
* CSceneManager는 GameManager에서 사용하는 Scene들의 부모 클래스이다.
> 내부에는 Scene의 가장 기본적인 함수들이 순수가상함수로 선언되어 있어, 만들고자하는 Scene에서 해당 함수들을 정의해 사용해야한다.
> 또한 각 Scene들에서는 Object들을 선언하여 관리하게 되어있으며 대표적으로 Player나 Enemy등이 있다.

_1. 화면구성_
* CGraphicsManager가 해당 역할을 해준다.
> 05.27_고정 프레임 방식을 도입하여 프레임 저하에 따른 오차를 줄였다.
* 기본적으로 화면은 좌측 상단을 기준으로 0, 0의 좌표에서 우측 하단은 사용자가 지정한 최대 크기를 가진다.
* 각 점은 int 자료형으로 구성되어 해당 지점을 기준으로 우측 하단 방향으로 그려준다.
* 즉, {40, 40}에 크기 {300, 20}짜리 그림을 그리는 경우 가로 40부터 340까지 세로 40부터 60까지 그려준다.

_2. Scene의 생성_
* CSceneManager를 상속받아 이용한다
* Init의 경우 Scene의 초기화에 이용한다. 이때, Surface로 받아오는 Screen은 이미지나 애니메이션의 초기화에 이용된다.
* Update와 Render는 실시간으로 호출되어 Update는 상태를 최신화시키고, Render는 해당 Scene에서 이용하는 이미지를 그린다.
* Exit는 게임이 종료될 때 일괄적으로 호출되며, 할당된 메모리들을 해제시켜주는 역할을 한다.

_3. 이미지 출력_
* CImageRenderer 클래스 변수를 선언하여 사용한다.
* 일반적으로 Scene이나 Object안에서 CImageRenderer를 만들며, SetImage를 통해 해당 클래스가 출력할 이미지를 설정할 수 있다.
* SetImage의 인자값은 Image파일의 경로(기본적으로 resource 디렉토리)와 출력해줄 Screen값(Surface)를 이용한다.
* Image를 찾을 수 없는 경우 콘솔에 해당 Image이름이 뜨며 에러메세지를 띄워준다.
* 이후, 이미지의 출력을 위해서는 해당 Scene의 Render에서 Image의 Render를 호출해주면 된다.
* Image또한 Surface가 할당되어 만들어 지는 것이므로 Scene의 Exit에서 ImageRenderer의 Exit를 호출한다.

_4. 애니메이션 출력_
 * CAnimationRenderer 클래스 변수를 선언하여 사용한다.
 * Image와 동일하게 Scene이나 Object안에서 만들며, 두 종류의 SetImage를 통해 이미지들을 설정할 수 있다.
 * 기본적인 SetImage는 인자 값으로 Image의 경로를 받아 Animation을 설정할 Image를 하나하나 세팅해주고 frameTime을 통해 각 Image간의 시간을 설정해준다. 또한, Screen 값을 받아 출력해줄 화면 인자 값을 받아온다.
 * 다른 방식의 SetImage는 Image의 이름에 규칙성이 있다면 사용이 가능하며 frame수를 받아 자동으로 Image를 세팅해준다.
 * 이때의 규칙은 다음과 같다 확장자가 소문자로 구성된 png파일이며 이미지의 이름이 aaaa_(num)이다.
 * 이때, (num)은 1부터 시작하여 순차적으로 있어야 한다.
 * 이렇게 세팅된 Image들은 Vector에 저장된다.
 * 이미지의 전환은 Render를 통해 deltaTime을 전송받고, 받은 deltaTime으로 frameTime과의 비교를 통해 Image를 넘겨준다.

_5. 사운드 출력_
 * 라이브러리 미구성
 
_6. 오브젝트 구성_
 * 오브젝트들을 만들 때 상속받아 이용하는 클래스이다.
 * 오브젝트에서 기본적으로 해야하는 동작들인 Init/Update/Render/Exit가 순수가상함수로 정의 되어 있다.
 * 또한, 기본적으로 오브젝트에서 필요한 변수들과 Set/Get 함수가 정의 되어있다.
