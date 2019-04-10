module Styles = {
  open Emotion;

  let headline = [%css
    [textAlign(`center), margin3(`rem(4.), `zero, `rem(2.))]
  ];
};

[@react.component]
let make = () =>
  <div>
    <h1 className=Styles.headline>
      {React.string("Sorry, couldn't find this page.")}
    </h1>
  </div>;
