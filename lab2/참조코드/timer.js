// 1초 후에
setTimeout(function () {
    console.log("2초가 지났습니다.");
}, 2000);
// 1초마다
k = setInterval(function () {
    console.log("1초 마다 호출됩니다.");
}, 1000);

setTimeout(function () {
    // 타이머를 제거합니다.
    clearInterval(k);
}, 2100);
