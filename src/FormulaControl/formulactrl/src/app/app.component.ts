import { Component } from '@angular/core';


@Component({
  
  selector: 'app-root',
  templateUrl: './app.component.html',
  styleUrls: ['./app.component.css']
})
export class AppComponent {
  title = 'Formula Calculator';
  myalfa: number;
  temperature: number;

  constructor(){
   this.myalfa =  3.9083 * Math.pow(10,  -3); 
   this.temperature = 0;
  }
  
  calculate (alf: number, val:number){
let R_zero : number =  100;
let r_term : number = 100;
let alfa: number =  3.9083 * Math.pow(10,  -3);

alfa = alf;
r_term=val;

let beta: number = -5.7750 * Math.pow(10, -7);
// old  double beta=  * pow(10, -7);
  
// let up:number = (-R_zero * alfa) + Math.sqrt(Math.pow(R_zero, 2)* Math.pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
// old up = (-R_zero * alfa) + sqrt(pow(R_zero, 2)* pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term));
// let down : number = 2 * R_zero * beta;
console.log("R_zero: ")
console.log(R_zero)
console.log("alfa: ")
console.log(alfa)

console.log("beta: ")
console.log(beta)
console.log("r_term: ")
console.log(r_term)

console.log(4* R_zero * beta)
let up : number =(-R_zero * alfa) + Math.sqrt(Math.pow(R_zero, 2)* Math.pow(alfa, 2) - 4* R_zero * beta * (R_zero - r_term))
let down : number = 2 * R_zero * beta;
let temp : number = up/down;

//  temp = -100 * a + sqrt(pow (100, 2) * pow(a, 2) - 4*100*b*(100 - r)) / 2 * 100 * b;
console.log("resistance: ")
console.log(val)
console.log("temp: ")
console.log(temp)

this.myalfa = alfa;
this.temperature = temp;


  }
}
