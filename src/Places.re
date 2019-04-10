module Styles = {
  open Emotion;

  let list = [%css
    [margin(`auto), maxWidth(`px(632)), margin3(`rem(1.), `auto, `zero)]
  ];

  let preview = [%css
    [
      width(`px(632)),
      height(`px(280)),
      borderRadius(`px(6)),
      marginBottom(`rem(1.)),
      boxShadows([
        (`px(0), `px(2), `px(4), `px(0), `rgba((0, 0, 0, 0.2)), false),
        (
          `px(0),
          `px(0),
          `px(0),
          `px(2000),
          `rgba((255, 255, 255, 0.4)),
          true,
        ),
      ]),
      backgroundSize(`cover),
      backgroundPosition(`keywords((`center, `center))),
      position(`relative),
    ]
  ];

  let headline = [%css [fontSize(`rem(1.5))]];

  let link = [%css [textDecoration(`none), color(`hex("000"))]];

  let content = [%css [padding(`rem(1.))]];

  let description = [%css
    [whiteSpace(`nowrap), overflow(`hidden), textOverflow(`ellipsis)]
  ];

  let attribution = [%css
    [
      display(`block),
      fontSize(`rem(0.4)),
      color(`hex("000")),
      marginTop(`rem(2.5)),
    ]
  ];

  let filterInput = [%css
    [
      fontSize(`rem(0.8)),
      boxSizing(`borderBox),
      display(`block),
      width(`px(632)),
      padding2(`rem(0.4), `rem(0.4)),
      borderRadius(`px(6)),
      margin(`auto),
      border(`px(1), `solid, `hex("ccc")),
    ]
  ];
};

[@react.component]
let make = () => {
  let (term, setTerm) = React.useState(() => "");

  let filteredPlaces =
    Data.places->Belt.List.keep(place =>
      term->String.lowercase->Js.String.includes(place.name->String.lowercase)
    );

  <div>
    <input
      value=term
      placeholder={j|Filter by name …|j}
      onChange={event => setTerm(ReactEvent.Form.target(event)##value)}
      className=Styles.filterInput
    />
    <ul className=Styles.list>
      {filteredPlaces
       ->Belt.List.map(place => {
           let imageUrl = place.image.url;
           let id = place.id;

           <li
             key={place.id}
             className=Styles.preview
             style={ReactDOMRe.Style.make(
               ~backgroundImage={j|url($imageUrl)|j},
               (),
             )}>
             <a href={j|/place/$id|j} className=Styles.link>
               <div className=Styles.content>
                 <h2 className=Styles.headline>
                   {React.string(place.name)}
                 </h2>
                 <p className=Styles.description>
                   {React.string(place.description)}
                 </p>
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
               </div>
             </a>
           </li>;
         })
       ->Belt.List.toArray
       ->React.array}
    </ul>
  </div>;
};
