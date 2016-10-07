<div class="problem">
  <div class="description">
    <div class="title">문제 1</div>
    <p>어떤 양의 정수 집합 S[x,y]는 x에서 y까지 y-x+1개의 서로 다른 연속된 정수를 나타낸다. 예를 들면 S[5,12]= { 5, 6, 7, 8, 9, 10, 11, 12 }, S[1234, 1240]={1234, 1235, 1236, 1237, 1238, 1239, 1240} 이다.
<br><br>
<br>&nbsp;우리는 S의 원소를 이진수로 변환하여 순서대로 나열할 때 각 단계에서 변화된 비트의 개수를 구하고자 한다. 예를 들어 보자. 10에서 11로 변할 때 변화된 비트는 1개이며, 15에서 16이 될 때 변화된 비트는 5개이다. 만일 S[11,15]인 11부터 15까지 매 단계 변화된 비트의 개수를 구해보면 3+1+2+1 = 7이 된다. 같은 식으로 S[22,25]의 원소 순서대로 변화된 비트를 계산해보면 1+4+1=6임을 알 수 있다.
<br><br>
<br><img src="https://s3.ap-northeast-2.amazonaws.com/codemonster/problems/5/image1.png" style="display:block;margin:0 auto;"></p>
  </div>
  <div class="input_constraints">
    <div class="title">[입력]</div>
    <p>입력 파일의 제일 첫째 줄에는 파일에 포함된 케이스의 수 T가 주어진다. 단, T ≤ 1,000이다. 각 케이스의 첫째 줄에 x,y 2개 양의 정수가 주어진다. 두 수의 범위는 2 ≤ x &lt; y ≤2^60 이다. 여러분은 x부터 y까지 모두 y-x 단계에서 변화된 비트의 총 개수를 계산하여 그 값을 출력해야 한다. 입력은 다음의 세 가지 종류로 주어진다.
<br><br>
<br>- Set 1: 2 ≤ x &lt; y ≤2^10,
<br>- Set 2: 2 ≤ x &lt; y ≤2^30,
<br>- Set 3: 2 ≤ x &lt; y ≤2^60.
</p>
  </div>
  <div class="output_constraints">
    <div class="title">[출력]</div>
    <p>각각의 질문 S[x,y]에 대해 변화된 비트의 개수를 계산하여 정수로 출력해야 한다.</p>
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
            <p>3
<br>11 15
<br>22 25
<br>220687542 1053328179</p>
          </td>
          <td>
            <p>7
<br>6
<br>1665281275</p>
          </td>
        </tr>
      </tbody>
    </table>
  </div>
</div>
