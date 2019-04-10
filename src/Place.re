module Styles = {
  open Emotion;

  let wrapper = [%css
    [margin(`auto), maxWidth(`px(632)), margin3(`rem(1.), `auto, `zero)]
  ];

  let nav = [%css
    [
      textAlign(`center),
      display(`block),
      margin3(`rem(4.), `zero, `rem(2.)),
      color(`hex("000")),
      fontSize(`rem(0.6)),
    ]
  ];

  let headline = [%css
    [textAlign(`center), margin3(`rem(4.), `zero, `rem(2.))]
  ];

  let preview = [%css
    [
      width(`px(632)),
      height(`px(280)),
      borderRadius(`px(6)),
      marginBottom(`rem(1.)),
      boxShadows([
        (`px(0), `px(2), `px(4), `px(0), `rgba((0, 0, 0, 0.2)), false),
      ]),
      backgroundSize(`cover),
      backgroundPosition(`keywords((`center, `center))),
      position(`relative),
    ]
  ];

  let attribution = [%css
    [display(`block), fontSize(`rem(0.5)), color(`hex("000"))]
  ];

  let description = [%css [color(`hex("333")), fontSize(`rem(0.8))]];
};

[@react.component]
let make = (~place: Data.place) => {
  let imageUrl = place.image.url;

  <div className=Styles.wrapper>
    <a href="/" className=Styles.nav> {React.string("Vienna")} </a>
    <h1 className=Styles.headline> {React.string(place.name)} </h1>
    <div
      className=Styles.preview
      style={ReactDOMRe.Style.make(~backgroundImage={j|url($imageUrl)|j}, ())}
    />
    {switch (place.image.attributionUrl) {
     | None =>
       <p className=Styles.attribution>
         {React.string(place.image.attribution)}
       </p>
     | Some(url) =>
       <a href=url className=Styles.attribution>
         {React.string(place.image.attribution)}
       </a>
     }}
    <p> {React.string(place.address)} </p>
    {switch (place.phone) {
     | None => React.null
     | Some(number) => <p> {React.string(number)} </p>
     }}
    {switch (place.email) {
     | None => React.null
     | Some(email) => <p> {React.string(email)} </p>
     }}
    <p className=Styles.description> {React.string(place.description)} </p>
  </div>;
};
