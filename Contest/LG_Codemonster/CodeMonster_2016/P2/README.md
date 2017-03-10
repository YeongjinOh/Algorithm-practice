<div class="problem">
  <div class="description">
    <div class="title">문제 2</div>
    <p>n개의 정점과 m개의 에지로 이루어진 그래프 G=(V,E)에서 각 에지 e∈E에 대역폭 b(e)&gt;0가 주어진다. 그래프 G는 연결 그래프로서 G의 임의의 두 정점에 대해서 그들을 연결하는 경로가 항상 존재한다. 그래프 G의 두 정점을 연결하는 경로 P에 대해서, 경로 P의 대역폭 b(P)를 P에 속하는 에지들의 대역폭 중 최소값으로 정의한다.
<br><br>
<br>우리는 그래프 G의 임의의 두 정점 s와 t를 연결하는 경로들 중에서 대역폭 b(P)가 최대가 되는 경로 P를 찾고 싶다. 이 경로를 s와 t의 최대 대역폭 경로라고 부르고 MBP(s,t)로 나타낸다.
<br>단, s=t 인 경우 MBP(s,t)=0이다.
<br><br>
<br>그래프 G=(V,E)와 Q개의 G의 두 정점 쌍 (s,t)가 주어질 때, 각 (s,t)의 최대 대역폭 경로 MBP(s,t)를 구해서 이 경로들의 대역폭의 합을 출력하는 프로그램을 작성하시오.
<br><br>
<br>예를 들어서, 아래 그림 1의 그래프에서 2개의 정점 쌍 (1, 2)와 (1, 4)에 대해서, 정점 1과 2를 연결하는 경로는 1 – 2, 1 – 3 – 2, 1 – 3 – 4 – 2의 3개 경로가 존재하고 최대 대역폭 경로는 1 – 3 – 4 – 2이고 대역폭은 3이다. 또한 정점 1과 4를 연결하는 경로는 1 – 2 – 4, 1 – 2 – 3 – 4, 1 – 3 – 4, 1 – 3 – 2 – 4이고 최대 대역폭 경로는 대역폭 3을 가지는 1 – 3 – 4이다. 따라서 이 최대 대역폭 경로들의 대역폭 합은 6이다.
<br><img src="https://s3.ap-northeast-2.amazonaws.com/codemonster/problems/6/image1.png" style="display:block;margin:0 auto;">
<br><br>
<br>* s=t 인 특수한 경우에 대한 MBP()의 정의는 MBP(s,t)=0으로 자연스럽게 확장되는 것으로 지문 작성되었으나 자연스럽지 않을 수 있음을 고려하여 문제 지문에 명시하였음</p>
  </div>
  <div class="input_constraints">
    <div class="title">[입력]</div>
    <p>입력 파일의 제일 첫째 줄에는 파일에 포함된 케이스의 수 T가 주어진다. 단, T ≤ 45이다. 각 케이스의 첫째 줄에 각각 그래프 G의 정점과 에지의 개수를 나타내는 두 정수 N과 M(2 ≤ N ≤ 10,000, 1 ≤ M ≤ 500,000)이 주어진다. 정점들은 정수 1부터 N으로 나타낸다. 다음 M개의 줄 각각에는 한 에지 e와 인접한 두 정점을 나타내는 정수 x와 y(1 ≤ x &lt; y ≤ N)와 e의 대역폭 b(e)를 나타내는 정수 z(1 ≤ z ≤ 100,000,000)가 빈칸을 사이에 두고 순서대로 주어진다. 다음 줄에는 두 정점 쌍들의 개수를 나타내는 정수 Q(1 ≤ Q ≤ 100,000)가 주어진다. 다음 Q개의 줄 각각에는 하나의 정점 쌍을 이루는 두 정점을 나타내는 두 정수 s와 t(1 ≤ s, t ≤ N)가 주어진다.
<br><br>
<br>입력은 다음의 두 가지 종류로 주어진다.
<br><br>
<br>- Set 1 : 2 ≤ N ≤ 1,000, 1 ≤ Q ≤ 1,000.
<br>- Set 2 : 별도의 제한이 없음.
</p>
  </div>
  <div class="output_constraints">
    <div class="title">[출력]</div>
    <p>각각의 질문에 대해서 Q개의 정점 쌍 (s, t)에 대한 최대 대역폭 경로 MBP(s, t)의 대역폭들의 합을 한 줄에 하나씩 출력한다.</p>
  </div>
  <div class="sample_testcase">
    <div class="title">[예시]</div>
    <table>
      <colgroup>
        <col width="50%">
        <col width="50%">
      </colgroup>
      <thead>
        <tr>
          <th>입력 예시</th>
          <th>출력 예시</th>
        </tr>
      </thead>
      <tbody>
        <tr>
          <td>
            <p>2
<br>3 3
<br>1 2 2
<br>1 3 1
<br>2 3 3
<br>1
<br>1 3
<br>4 5
<br>1 2 2
<br>1 3 3
<br>2 3 1
<br>2 4 3
<br>3 4 4
<br>2
<br>1 2
<br>1 4</p>
          </td>
          <td>
            <p>2
<br>6</p>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
</div>
